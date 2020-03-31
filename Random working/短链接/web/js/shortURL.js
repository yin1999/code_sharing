window.onload=function()
{
    function $(id){
        return typeof id === 'string'? document.getElementById(id) : null ;
    }

    let url = ""
    $('url').onchange=function()
    {
        //let regex = /^(https?|ftp|file):\/\/?[-a-zA-Z0-9_]+\.[-a-zA-Z0-9_]+[-a-zA-Z0-9_\.]*(\/.*)?$/;
        let ovalue=this.value;
        let scheme = /^(https?|ftp|file):\/\//;
        if(ovalue=='')
        {
            $('error1').innerHTML="网址不能为空！"
            $('error1').setAttribute("class",'error');
        }
        else
        {
            let flag = true
            if (scheme.test(ovalue) == false)
            {
                ovalue = "http://"+ovalue
                this.ovalue = ovalue
            }
            try {
                let url=new URL(ovalue)
            } catch(_) {
                flag = false
            }
            if(flag==false)
            {
                $('error1').innerHTML="网址格式错误！"
                $('error1').setAttribute("class",'error');
            }
            else
            {
                $('error1').innerHTML=""
                $('error1').className=null;
                url = ovalue
                return true
            }
        }
    }

    $('form').onsubmit=function() {
        if ($('error1').className == "null") {
            $('url').value = url
            return true;
        }
        return false;
    }

    $('short').onclick=function()
    {
        $('url').setAttribute("placeholder","请输入长网址");
        $('name').setAttribute("value","缩短网址");
        $('mod').value="0"
        $('error1').innerHTML=""
        $('error1').className=null;
    }

    $('long').onclick=function()
    {
        $('url').setAttribute("placeholder","请输入短网址");
        $('name').setAttribute("value","还原网址");
        $('mod').value="1"
        $('error1').innerHTML=""
        $('error1').className=null;
    }
}
