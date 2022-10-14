```
<!DOCTYPE html>
<html lang="zh-CN">
	<head>
		<meta charset="utf-8">
		<meta name="viewport" content="width=device-width">
		<title id="title">Here is the title</title>
		<link rel="shortcut icon" type="image/x-icon" href="file/image/head.png">
		<link rel="stylesheet" href="file/css/mdui.min.css"/>
		<link rel="stylesheet" href="file/css/milmon.css"/>
		<script src="file/script/milmon.js"></script>
		<script src="file/script/problem.js"></script>
		<script src="file/script/mdui.min.js"></script>
		<script>
			window.onload=function(){
			}
		</script>
		<script type="text/x-mathjax-config">MathJax.Hub.Config({tex2jax: {inlineMath: [['$', '$']], displayMath: [['$$', '$$']]}});</script>
        <script src="https://yhx-12243.github.io/OI-transit/additional_files/MathJax-master/MathJax.js?config=TeX-MML-AM_CHTML"></script>
	</head>
	<body class="mdui-theme-primary-purple" style="background: #B7EEF8;">
		<div id="main-container">
			<!-- ---------标题栏--------------- -->
			<div class="mc-appbar mdui-appbar-fixed mdui-appbar mdui-color-theme mdui-hoverable">
				<div class="toolbar mdui-toolbar">
					<span class="mdui-btn mdui-btn-icon mdui-ripple mdui-ripple-white" mdui-drawer="{target:'#main-drawer',overlay:true,swipe:true}">
						<i class="mdui-icon material-icons">menu</i>
					</span>
					<a href="/" class="mdui-btn mdui-btn-icon mdui-ripple mdui-ripple-white">
						<i class="mdui-icon material-icons" style="color: #fff;">home</i>
					</a>
					<a href="/problems" class="mdui-btn mdui-btn-icon mdui-ripple mdui-ripple-white">
						<i class="mdui-icon material-icons" style="color: #fff;">arrow_back</i>
					</a>
					<span class="mdui-typo-title" style="color: #fff;">title</span>
					<div class="mdui-toolbar-spacer"></div>
					<a href="/settings" class="mdui-btn mdui-btn-icon mdui-ripple mdui-ripple-white">
						<i class="mdui-icon material-icons" style="color: #fff;">settings</i>
					</a>
					<a href="" class="mdui-btn mdui-btn-icon mdui-ripple mdui-ripple-white">
						<i class="mdui-icon material-icons" style="color: #fff;">refresh</i>
					</a>
				</div>
			</div>

			<!-- ---------左侧菜单--------------- -->
			<div class="mdui-drawer mdui-drawer-close" id="main-drawer" style="background:rgb(52,152,219);color:white">
				<ul class="mdui-list">
					<a class="mdui-list-item mdui-ripple" href="/">
						<i class="mdui-list-item-icon mdui-icon material-icons" style="color:#fff;">home</i>
						<div class="mdui-list-item-content">首页</div>
					</a>
					<div class="mdui-divider mdui-m-y-0"></div>
					<a class="mdui-list-item mdui-ripple" href="/blog">
						<i class="mdui-list-item-icon mdui-icon material-icons" style="color:#fff;">library_books</i>
						<div class="mdui-list-item-content">博文列表</div>
					</a>
					<a class="mdui-list-item mdui-ripple mdui-list-item-active" href="/problems">
						<i class="mdui-list-item-icon mdui-icon material-icons" style="color:#fff;">work</i>
						<div class="mdui-list-item-content">题目中心</div>
					</a>
					<a class="mdui-list-item mdui-ripple" href="/tools">
						<i class="mdui-list-item-icon mdui-icon material-icons" style="color:#fff;">apps</i>
						<div class="mdui-list-item-content">工具中心</div>
					</a>
				</ul>
			</div>

			<div id="main-page">
			</div>

			<!-- -----------联系方式-------------- -->

			<footer style="background:#444;" id="page-footer">
				<div class="mdui-container mdui-p-t-3 mdui-text-center">
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
					<p class="mdui-typo" style="color: white; font-size: 13px;">Powered by <a href="//mdui.org">MDUI</a> & <a href="//github.com/Molmin/Milmon-Page">Milmon Page</a> | <a href="/about">about</a></p>
				</div>
			</footer>
		</div>
		<script src="file/script/particlelines.js"></script>
	</body>
</html>

```
