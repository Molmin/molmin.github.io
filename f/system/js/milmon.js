function $(x){
	return document.getElementById(x);
}
function getParam(paramName) { 
	paramValue="",isFound=!1; 
	if(this.location.search.indexOf("?")==0 && this.location.search.indexOf("=")>1) { 
		arrSource=unescape(this.location.search).substring(1,this.location.search.length).split("&"),i=0; 
		while(i<arrSource.length && !isFound)
			arrSource[i].indexOf("=")>0 && arrSource[i].split("=")[0].toLowerCase()==paramName.toLowerCase() && 
				(paramValue=arrSource[i].split("=")[1], isFound=!0), i++;
	} 
	return paramValue=="" && (paramValue=null), paramValue;
}
function message(s){
	mdui.snackbar({message:s,position:'bottom'});
}
function copy(str){
	const text_area=document.createElement('textarea');
	document.body.appendChild(text_area);
	text_area.setAttribute('id','copier');
	$('copier').value=str;
	text_area.select();
	document.execCommand('copy');
	document.body.removeChild(text_area);
	message('内容已复制到剪贴板');
}
function newrandomid(){
	var chars="0123456789abcdef",result="";
	for(var i=0;i<32;i++)
		result=result+chars[parseInt(Math.random()*16)];
	return result;
}
function getcookie(str){
	var s="";
	for(var i=0;i<str.length;i++){
		var flag=false;
		var charset="1234567890abcdef";
		for(var j=0;j<16;j++)
			if(charset[j]==str[i])flag=true;
		if(flag)s=s+str[i];
	}
	return s;
}
function hashpassword(s){
	s="sjq018AD3"+s+"SFD29dja";
	var a=new Array();
	var charset="1234567890abcdef";
	for(var i=0;i<32;i++)
		a[i]=s.charCodeAt(i%s.length)%16;
	var p=0;
	for(var i=0;i<s.length;i++){
		var tmp=s.charCodeAt(i)+83;
		tmp=tmp*tmp*tmp;
		while(tmp>0){
			a[p]+=tmp%10;
			p++;
			if(p==32)p=0;
			tmp=(tmp-tmp%10)/10;
		}
	}
	var str="";
	for(var i=0;i<32;i++)
		str=str+charset[a[i]%16];
	s=str+s+str;
	a=new Array();
	for(var i=0;i<32;i++)
		a[i]=s.charCodeAt(i%s.length)%16;
	var p=0;
	for(var i=0;i<s.length;i++){
		var tmp=s.charCodeAt(i)+83;
		tmp=tmp*tmp*tmp;
		while(tmp>0){
			a[p]+=tmp%10;
			p++;
			if(p==32)p=0;
			tmp=(tmp-tmp%10)/10;
		}
	}
	var str="";
	for(var i=0;i<32;i++)
		str=str+charset[a[i]%16];
	return str;
}
function loadfile(filename,func){
	let url=filename;
	let httpRequest=new XMLHttpRequest();
	httpRequest.open('GET',url,true);
	httpRequest.send();
	httpRequest.onreadystatechange=function(){
		if (httpRequest.readyState==4 && httpRequest.status==200)
			func(httpRequest.responseText);
	};
}
function initgitalk(gitalkid){
	var gitalk = new Gitalk({
		clientID: '661f53e48c0ee62637bb',
		clientSecret: 'f813867ae5c80568f820d5035685cba9f7e9678e',
                repo: 'molmin.github.io',
                owner: 'Molmin',
                admin: ['Molmin'],
                id: gitalkid,
                distractionFreeMode: false
	});
	$('gitalk-container').innerHTML='<p style="color: grey;">Gitalk ID: '+gitalkid+'</p><div id="gitalk-inside-container"></div>';
	gitalk.render('gitalk-inside-container');
}

var markdown_content;
function markdown(file){
	var result="";
	var titlegrade=0,listgrade=0;
	var instrong=false,inem=false,ininlinecode=false;
	var contents=[],contentstotal=0;
	for(var i=0;i<file.length;i++){
		if(i==0||(file.charAt(i-1)=='\n'&&i>=2&&file.charAt(i-2)=='\n')){
			if(file.charAt(i)=='#'){
				var tot=0;
				while(file.charAt(i)=='#')i++,tot++;
				titlegrade=tot;
				contents[contentstotal++]=[String(titlegrade),"",newrandomid()];
				result=result+"<h"+titlegrade+" id='"+contents[contentstotal-1][2]+"'>";
				continue;
			}
			else if(file.charAt(i)=='`'){
				while(file.charAt(i)=='`')i++;
				var lang="";
				while(file.charAt(i)!='\n')lang=lang+file.charAt(i),i++;
				if(lang=="")lang="text";
				var tmp="";
				while(file.substring(i+1,i+5)!='\n```'){
					i++;
					if(file.charAt(i)=='\t')tmp=tmp+"    ";
					else tmp=tmp+file.charAt(i);
				}
				i=i+4;
				var id=newrandomid();
				result=result+'<div class="code-divoutside"><button class="code-copybutton code-copybutton-cursor" onclick="copy($(\''+id+'\').innerText);">复制</button><div class="code-divinside mdui-dialog-content"><pre class="code-pre" id="'+id+'">'+hljs.highlight(tmp,{language:lang}).value+'</pre></div></div>';
				continue;
			}
			else{
// 				var j=i,total=0;
// 				while(file.charAt(i)!='\n'&&j<file.length&&file.charAt(i)!='-')j++,total++;
// 				if(file.charAt(j)=='\n
// 				int grade=parseInt(total/2.0);
// 				if(grade<
				result=result+"<p>";
				titlegrade=0;
			}
		}
		if(file.charAt(i)=='\n'&&file.charAt(i-1)!='\n'&&file.charAt(i+1)!='\n')
			result=result+" ";
		if(file.charAt(i)!='\n'){
			if(file.charAt(i)=='`'){
				if(ininlinecode)result=result+"</code>";
				else result=result+"<code class='code-inline'>";
				ininlinecode=!ininlinecode;
			}
			else if(file.charAt(i)=='*'){
				var total=1;
				while(file.charAt(i+1)=='*')i++,total++;
				if(total==1){
					if(inem)result=result+"</em>";
					else result=result+"<em>";
					inem=!inem;
				}
				if(total==2){
					if(instrong)result=result+"</strong>";
					else result=result+"<strong>";
					instrong=!instrong;
				}
				if(total==3){
					if(inem){
						if(instrong)result=result+"</em></strong>";
						else result=result+"</em><strong>";
					}
					else{
						if(instrong)result=result+"</strong><em>";
						else result=result+"<strong><em>";
					}
					inem=!inem;
					instrong=!instrong;
				}
			}
			else if(file.charAt(i)=='!'&&(i==0||file.charAt(i-1)=='\n')&&file.charAt(i+1)=='['){
				while(file.charAt(i)!=']')i++;
				while(file.charAt(i)!='(')i++;
				result=result+"<img style='max-width: 100%;' src='";
				while(file.charAt(i+1)!=')')
					i++,result=result+file.charAt(i);
				result=result+"'>";
				i++; continue;
			}
			else{
				result=result+file.charAt(i);
				if(titlegrade!=0)contents[contentstotal-1][1]=contents[contentstotal-1][1]+file.charAt(i);
			}
		}
		if(i==file.length-1||(file.charAt(i+1)=='\n'&&file.charAt(i+2)=='\n')){
			if(titlegrade==0)result=result+"</p>";
			else result=result+"</h"+titlegrade+">";
		}
	}
	markdown_content="";
	var mintitle=6;
	for(var i=0;i<contents.length;i++)
		if(Number(contents[i][0])<mintitle)mintitle=Number(contents[i][0]);
	for(var i=0;i<contents.length;i++){
		if(Number(contents[i][0])<=2)markdown_content=markdown_content+'<p style="font-size: 14px; line-height: 16px; cursor: pointer;" onclick="$(\''+contents[i][2]+'\').scrollIntoView(true);" class="mdui-text-truncate">';
		else markdown_content=markdown_content+'<p style="font-size: 12px; line-height: 16px; cursor: pointer;" onclick="$(\''+contents[i][2]+'\').scrollIntoView(true);" class="mdui-text-truncate">';
		for(var j=1;j<=Number(contents[i][0]-mintitle);j++)
			markdown_content=markdown_content+'&nbsp;&nbsp;&nbsp;&nbsp;';
		markdown_content=markdown_content+contents[i][1]+"</p>";
	}
	return result;
}

function getvalue(key){
	if(window.localStorage)
		return window.localStorage.getItem(key);
	else{
		message("浏览器不支持 Localstorage");
		return undefined;
	}
}
function setvalue(key,val){
	if(window.localStorage)
		window.localStorage.setItem(key,val);
	else{
		message("浏览器不支持 Localstorage");
		return undefined;
	}
}
function deletevalue(key){
	if(window.localStorage)
		window.localStorage.removeItem(key);
	else{
		message("浏览器不支持 Localstorage");
		return undefined;
	}
}

var footerisloaded=false;
setTimeout(footeronload,300);
function footeronload(){
	if($('page-footer')==null){setTimeout(footeronload,300);return;}
	if(footerisloaded)return;
	if(window.location.pathname.split('/about')[0]=="")return;
	footerisloaded=true;
	$('page-footer').innerHTML=`
		<div class="mdui-container mdui-p-t-3">
			<a class="mdui-btn mdui-btn-icon" mdui-tooltip="{content:'GitHub'}" href="https://github.com/Molmin/">
				<img src="/file/image/github.png" class="mdui-img-circle" width="20px" height="20px" style="margin:7px 0px 0px 0px;">
			</a>
			<a class="mdui-btn mdui-btn-icon" mdui-tooltip="{content:'腾讯 QQ'}" href="tencent://AddContact/?subcmd=all&uin=115549630">
				<img src="/file/image/qq.ico" width="20px" height="20px" style="margin:7px 0px 0px 0px;">
			</a>
			<a class="mdui-btn mdui-btn-icon" mdui-tooltip="{content:'洛谷'}" href="https://www.luogu.com.cn/user/234641">
				<img src="/file/image/luogu.ico" width="20px" height="20px" style="margin:7px 0px 0px 0px;">
			</a>
			<a class="mdui-btn mdui-btn-icon" mdui-tooltip="{content:'CodeForces'}" href="https://codeforces.com/profile/liujiameng">
				<img src="/file/image/codeforces.png" width="20px" height="20px" style="margin:8px 0px 0px 0px;">
			</a>
			<a class="mdui-btn mdui-btn-icon" mdui-tooltip="{content:'Atcoder'}" href="https://atcoder.jp/users/liujiameng">
				<img src="/file/image/atcoder.png" width="20px" height="20px" style="margin:8px 0px 0px 0px;">
			</a>
			<div style="float: right;">
				<p class="mdui-typo" style="color: white; font-size: 13px;">Powered by <a href="//mdui.org">MDUI</a> & <a href="//github.com/Molmin/Milmon-Page">Milmon Page</a> | <a href="/about">about</a></p>
				<p class="mdui-typo" style="color: white; font-size: 13px;"><span id="busuanzi_container_site_pv">共 <span id="busuanzi_value_site_pv"></span> 访问</span>&nbsp;&nbsp;|&nbsp;&nbsp;<span id="busuanzi_container_site_uv">共 <span id="busuanzi_value_site_uv"></span> 访客</span></p>
			</div>
		</div>
	`;
}
