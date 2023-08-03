// ==UserScript==
// @name         海亮 OIer 专属：计时器破解器
// @version      1.0.1
// @description  在开始计时之前查看题面！！！
// @author       Milmon
// @match        https://oj.hailiangedu.com/*
// @grant        none
// ==/UserScript==

async function start_script() {
    const url = window.location.pathname;
    const domainId = /^\/d\/[a-zA-Z0-9]+?\//.test(url)
        ? /^\/d\/([a-zA-Z0-9]+?)\//.exec(url)[1]
        : 'system';
    var pid = window.prompt(`请输入该域中的一道题目的题目编号（例如“C23028”“217”等）`);
    if (!/^[a-zA-Z0-9]+$/.test(pid)) {
        window.alert(`输入不合法。`);
        return;
    }

    const response = await fetch(`/d/${domainId}/p/${pid}/files`, {
        method: "GET",
        headers: {
            accept: "application/json",
        },
    });
    const data = await response.json();
    if (data.error) {
        window.alert(`题目不存在。`);
        return;
    }

    const { pdoc } = data;
    var content = {};
    try {
        // 处理 Hydro 的玄学 content
        var tmp = JSON.parse(pdoc.content);
        content = tmp;
    }
    catch (e) {
        content = { zh: pdoc.content };
    }

    var html = '';
    for (var lang in content) {
        var text = content[lang];
        while (text != text.replace(`](file://`, `](/d/${domainId}/p/${pid}/file/`))
            text = text.replace(`](file://`, `](/d/${domainId}/p/${pid}/file/`);
        const res = await fetch(`/markdown`, {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
            },
            body: JSON.stringify({ text })
        });
        html += await res.text();
    }
    if (pdoc.additional_file && pdoc.additional_file.length > 0) {
        html += `<h2>附加文件</h2>`;
        for (var file of pdoc.additional_file)
            html += `<p><a href="/d/${domainId}/p/${pid}/file/${file.name}">${file.name}</a></p>`;
    }

    await new window.Hydro.components.InfoDialog({
        $body: `
            <div class="typo" style="
                max-width: 600px;
                max-height: 400px;
                overflow: auto;
            ">
                ${html}
            </div>
        `,
    }).open();
}

(function () {
    $(document).ready(() => {
        $(document).keyup((event) => {
            if (event.keyCode == 89 && event.ctrlKey) start_script();
        });
    });
})();