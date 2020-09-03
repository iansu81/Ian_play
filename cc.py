# # encoding:utf-8
# import csv
# with open('cc.csv', newline='', encoding='gb18030') as csvfile:
#     spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')     
#     i = 0
#     while i < 10 :
#         for row in spamreader:
#             print(', '.join(row))
#             i += 1



import codecs
F=codecs.open('cc.csv','r','gb18030')
content=F.read()
F.close()
print(content)