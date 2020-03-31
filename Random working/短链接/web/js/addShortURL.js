window.onload=function()
{
    function $(id){
        return typeof id === 'string'? document.getElementById(id) : null ;
    }
    $('copyURL').addEventListener('click', function () {
        const input = document.querySelector('#url');
        input.select();
        if (document.execCommand('copy')) {
            console.log('复制成功');
            $('url').select()
        }
        else {
            console.log('复制失败');
        }
    })

    $('url').onfocus=function() {
        this.select()
    }
}