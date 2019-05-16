from Source import TextClassification
import pickle

with open('training.pickle', 'rb') as file:
    content_list = pickle.load(file)
with open('trainlable.pickle', 'rb') as file:
    label_list = pickle.load(file)
model = TextClassification(content_list, label_list)
model.trainModel()
model.store_idList()
#for i in range(5):
    #S = input()
    #L = [S]
    #model.test(L)

# model.printConfusionMatrix()
# model.printReportTable()
