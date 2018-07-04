from gensim.models import word2vec

sentences=word2vec.Text8Corpus('data.txt')
model=word2vec.Word2Vec(sentences,size=300,window = 5,min_count = 2,workers = 4)
#size代表词向量维度
#window代表窗口大小
#min_dount代表去掉出现次数小于2的低频词
#workers代表线程数

output = 'feature_article.txt'
outfile = open(output,'w')
filename = 'feature_words.txt'
file = open(filename,'r')
list = []
for line in file:
    listdata = []
    words = line.split(' ')
    for word in words:
        try:
            if (len(listdata)==0):
                #pass
                listdata = model[word]
                #print(listdata)
            else:
                #pass
                listdata = listdata + model[word]
        except:
            pass
    for number in listdata:
        outfile.write(str(number) + ' ')
    outfile.write('\n')  
outfile.close()
file.close()

