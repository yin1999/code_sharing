import smtplib
from email.mime.text import MIMEText
from email.header import Header

Username = '用户名'
Passwd = '密码'

user_passwd = 'test passwd'
mail_to = '1260001095@qq.com'

mail_host = 'smtp.163.com'
mail_user = 'yin199909@163.com'
mail_passwd = 'iottest123'


sender = 'yin199909@163.com'
receiver = '{}'.format(mail_to)

msg = '''
<!DOCTYPE html>
<html lang="zh_CN">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Document</title>
</head>
<body>
    <table style="width: 800px; background-color: #1f2126;" align="center" cellspacing="0" cellpadding="0">
        <tbody><tr>
            <td bgcolor="#1f2126;">
    
                <table style="width: 800px; background-color: #393836;" align="center" cellspacing="0" cellpadding="0">
                    <tbody><tr>
                        <td style="height: 65px; background-color: #171a21; border-bottom: 1px solid #4d4b48;">
                            <img src="https://github.com/yin1999/code_sharing/raw/master/ESTA/%E7%89%A9%E8%81%94%E7%BD%91%E5%88%9B%E6%83%B3%E7%A7%80/resource%20files/teamlogo.jpg" width="81.25" height="65">
                            <div style="font-size: 20px;FLOAT: right; position:relative; top:20px; right: 100px; color:#06beff">承安-最有亲和力的新闻网站
                            </div>
                        </td>
                    </tr>
                </tbody></table>
    
    
                                <table id="check_out_more_ctn" style="width: 800px; background-color: #393836;" align="center" cellspacing="0" cellpadding="0">
                        <tbody><tr>
                            <td bgcolor="#1f2126">
                                <table width="470" border="0" align="center" cellpadding="0" cellspacing="0" style="padding-left: 5px; padding-right: 5px;">
                                    <tbody><tr bgcolor="#1f2126">
                                        <td style="padding-top: 32px;">
                                            <span style="font-size: 24px; color: #06beff; font-family: Arial, Helvetica, sans-serif; font-weight: bold;">
                                                {}您好！
                                            </span><br>
                                            <span style="font-size: 17px; color: #c6d4df; font-family: Arial, Helvetica, sans-serif;">
                                                您的原始密码为：
                                            </span>
                                        </td>
                                    </tr>
                                </tbody></table>
                            </td>
                        </tr>
                    </tbody></table>
                            <table style="width: 800px; background-color: #1f2126" align="center" cellspacing="0" cellpadding="0">
        <tbody><tr>
            <td bgcolor="#1f2126">
                <table width="470" border="0" align="center" cellpadding="0" cellspacing="0" style="padding-left: 5px; padding-right: 5px;">
                    <tbody><tr>
                        <td valign="top" bgcolor="#1f2126" style="padding-top: 10px;">
                        </td>
                    </tr>
    
    
    
                    <tr valign="top" bgcolor="#1f2126" style="margin: 0; padding: 0;">
                        <td>
                            <table style="background-color: #2e3138; width: 100%;">
                                <tbody><tr>
                                    <td style="padding-top: 13px; padding-left: 17px; padding-bottom: 2px;">
                                        <p style="font-size: 20px; color: #e1e1e1; font-family: Arial, Helvetica, sans-serif; margin:0; padding:0;">
                                            {}
                                        </p>
                                    </td>
                                </tr>
                            </tbody></table>
                            <table style="width: 100%" cellpadding="0" cellspacing="0">
                                <tbody><tr height="14" style="background-color: #2e3138; line-height: 14px;">
                                    <td style="width: 100%"></td>
                                </tr>

                                <tr height="25" style="background-color: #1f2126;">
                                    <td width="1">
                                            <p style="font-size: 15px; color: #ffffff; font-family: Arial, Helvetica, sans-serif; padding:0;">
                                                如果你没有申请过忘记密码，请忽略这封邮件。<br>
                                                祝您在承安新闻阅读愉快!<br>
                                            </p>
                                    </td>
                                    <td></td>
                                    <td width="12"></td>
                                    <td width="1"></td>
                                </tr>
    
                            </tbody></table>
    
                        </td>
                    </tr>
                </tbody></table>
            </td>
        </tr>
    </tbody></table>
                                <table id="check_out_more_ctn" style="width: 800px; background-color: #393836;" align="center" cellspacing="0" cellpadding="0">
                        <tbody><tr>
                            <td bgcolor="#1f2126">
                                <table width="470" border="0" align="center" cellpadding="0" cellspacing="0" style="padding-left: 5px; padding-right: 5px;">
                                    <tbody>
                                    <tr>
                                        <td style="padding-top: 40px; padding-bottom: 32px">
                                            <p style="font-size: 12px; color: #61696d; font-family: Arial, Helvetica, sans-serif; padding:0;">
                                                这篇邮件是由系统自动发送，请不要回复这封邮件。<br>
                                                如果有任何问题，欢迎给管理员<a class="bodylink" href="Mailto:1140416327@qq.com" rel="noopener" target="_blank">发送邮件</a>。
                                            </p>
                                        </td>
                                    </tr>
                                </tbody></table>
                            </td>
                        </tr>
                    </tbody></table>
    
    
        <table width="800" border="0" align="center" cellpadding="0" cellspacing="0">
        <tbody><tr style="background-color: #000000;">
            <td style="padding: 12px 24px;">
                <table cellpadding="0" cellspacing="0">
                    <tbody><tr>
                        <td width="92">
                        </td>
                        <td style=" font-size: 11px; color: #595959; padding-left: 12px;">
                            © 承安新闻
                        </td>
                    </tr>
                </tbody></table>
            </td>
        </tr>
    </tbody></table>
    
            </td>
        </tr>
    </tbody></table>
</body>
</html>
'''.format(Username, Passwd)

message = MIMEText(msg, 'html', 'utf-8')
message['From'] = Header('admin<%s>' % sender, 'utf-8')
message['To'] = receiver

subject = '找回密码'
message['Subject'] = Header(subject, 'utf-8')

try:
    smtpObj = smtplib.SMTP_SSL(mail_host, 465)
    smtpObj.login(mail_user, mail_passwd)
    smtpObj.sendmail(sender, receiver, message.as_string())
    print("邮件发送成功")
except smtplib.SMTPException:
    print("邮件发送失败")