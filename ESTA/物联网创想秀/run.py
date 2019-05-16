from Source import TextClassification
import tensorflow as tf
import pickle
import tensorflow.contrib.keras as kr
import numpy as np


Input = ['不怕牛B的对手，就怕像猪的队友。', '这篇文章写得不错']
f = open('./idList.pickle', 'rb')
word2id_dict = pickle.load(f)


def content2idList(content):
    return [word2id_dict[word] for word in content if word in word2id_dict]


def content2X(content_list):
    idlist_list = [content2idList(content) for content in content_list]
    X = kr.preprocessing.sequence.pad_sequences(idlist_list, 600)
    return X


graph = tf.Graph()
with graph.as_default():
    init = tf.group(tf.global_variables_initializer(), tf.local_variables_initializer())
    sess = tf.Session()
    sess.run(init)
    with sess.as_default():
        saver = tf.train.import_meta_graph('./model/cnn_train-10000.meta')
        saver.restore(sess, tf.train.latest_checkpoint('./model'))
    X_holder = graph.get_operation_by_name('inputs/X_input').outputs[0]
    predict = graph.get_collection('Predict_Y')[0]
    if type(Input) == str:
        Input = [Input]
    batch_X = content2X(Input)
    predict_y = sess.run(predict, feed_dict={X_holder:batch_X})
    for example in predict_y:
        if example == 0:
            print('ham')
        else:
            print('spam')