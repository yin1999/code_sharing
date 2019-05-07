import pandas as pd

df = pd.read_csv('./city_people.csv',index_col='id')
df['总收入'] = df['收入1'] + df['收入2']
df['平均收入'] = df['总收入'] // 2
print('总收入\n', df['总收入'], '平均收入\n', df['平均收入'])

print('上海人的明细记录\n', df[df['city'] == '上海'])
print('杭州人的明细记录\n', df[df['city'] == '杭州'])
print('第一项收入明细\n', df['收入1'])
#DataFrame.loc[row_indexer,column_indexer]
print('年纪小于45岁的两项收入明细\n', df.loc[df['年龄'] < 45, ['收入1', '收入2']])
print('男生的两项收入明显\n', df.loc[df['sex'] == '男'], ['收入1', '收入2'])
print('小于45岁的女生的两项收入明细\n', df.loc[(df['sex'] == '女') & (df['年龄'] < 45), ['收入1', '收入2']])
df_grouped = df.groupby(by='sex')
print('收入总和\n', df_grouped['收入1'].sum())
print('平均收入\n', df_grouped['收入1'].mean())
