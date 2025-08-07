function isnumber(x){
	return (/(^[1-9]\d*$)/.test(x));
}
function checkprime(){
	var x=$('checkprimeval1').value;
	if(!isnumber(x)){
		$("checkprime_result").innerHTML="<font style='color: red;'>&nbsp;&nbsp;\""+x+"\" is not a positive integer.</font>";
		return;
	}
	var x1=Number(x),x2=Math.sqrt(x1),flag=true;
	for(var i=2;i<=x2&&flag;i++)
		if(x1%i==0)flag=false;
	if(flag&&x1>=2)$("checkprime_result").innerHTML="<font style='color: green;'>&nbsp;&nbsp;"+x1+" is a prime number.</font>";
	else $("checkprime_result").innerHTML="<font style='color:red;'>&nbsp;&nbsp;"+x1+" is not a prime number.</font>";
}
function randomstring(){
	var len=$('randomstringval1').value;
	var charSet=$('randomstringval2').value;
	if(!isnumber(len)){
		$("randomstring_result").innerHTML="<font style='color: red;'>&nbsp;&nbsp;\""+len+"\" is not a positive integer.</font>";
		return;
	}
	if(charSet==""){
		$("randomstring_result").innerHTML="<font style='color: red;'>&nbsp;&nbsp;Charset is empty.</font>";
		return;
	}
	var str="",charnum=charSet.length;
	for(var i=1;i<=Number(len);i++)
		str=str+charSet[parseInt(Math.random()*charnum)];
	$("randomstring_result").innerHTML="&nbsp;&nbsp;"+str;
	if(copy(str))message('内容已复制到剪贴板');
}
function randomstring_reset(){
	var x=$('randomstringtmp1').value;
	if(x=="1"){
		$('randomstringval1').value="16";
		$('randomstringval2').value="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz012345678901234567890123456789~!@#$%^&*()_+{}|:\"<>?`-=[]\;',./";
	}
	if(x=="2"){
		$('randomstringval1').value="32";
		$('randomstringval2').value="0123456789abcdef";
	}
	if(x=="3"){
		$('randomstringval1').value="4";
		$('randomstringval2').value="0123456789abcdefghijklmnopqrstuvwxyz";
	}
	if(x=="4"){
		$('randomstringval1').value="64";
		$('randomstringval2').value="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz01234567890123456789";
	}
	mdui.updateTextFields();
}
