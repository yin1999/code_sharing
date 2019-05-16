物联网创想秀文本分类器
====================
文件夹内的程序为关于文本分类的机器学习源码<br>
# 依赖项
    python
    tensorflow
    pickle
    collections
    sklearn
    numpy
    pandas
#使用方法
* 将文本列表存入`training.pickle`,将文本标签存入`trainlable.pickle`
* 运行`test.py`，开始训练模型（可以修改`Source.py`中的参数）
* 修改`run.py`中的`第8、9行`的参数，读取模型并对输入的文本进行猜测（按需要修改`第8行`后的数据，输出对文本的猜测结果
* 运行`run.py`即可获得结果
