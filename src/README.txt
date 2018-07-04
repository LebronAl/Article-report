①在“提取关键词”程序中配置文档信息集合"raw-data.txt"(未配置)和停用词列表"ignore-words.txt"(已配置)，然后提取出每篇文章的12个关键词，输出到“feature_words.txt”里面
②将上一个程序的输出结果"feature_words.txt"(未配置)拷贝到“深度学习生成词向量”程序中，再配置初级语料库"data.txt"(已配置)，该程序输出每篇文章的特征向量"feature_article.txt”
③将上一个程序的输出结果"feature_article.txt"(未配置)拷贝到“论文推荐”程序中，再配置用户训练集"user-info-train.txt"(未配置)和用户测试集"user-info-test.txt"(未配置),该程序输出结果"result.txt"