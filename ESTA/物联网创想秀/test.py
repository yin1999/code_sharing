from Source import TextClassification
import pickle

## =============================
## 导入训练数据
with open('training.pickle', 'rb') as file:
    content_list = pickle.load(file)
with open('trainlable.pickle', 'rb') as file:
    label_list = pickle.load(file)
    
model = TextClassification(content_list, label_list)
model.trainModel()
model.store_idList()   # 保存文字转id的字典列表
## ============================
## 输出统计数据
model.printConfusionMatrix()
model.printReportTable()
