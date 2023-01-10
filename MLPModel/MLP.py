from sklearn.neural_network import MLPClassifier
import pandas as pd
import numpy as np

# target.to_csv("targetBlack.csv", index=False)
# data.to_csv("dataChessBlack.csv", index=False)

data = pd.read_csv("test.csv")
target = pd.read_csv("target.csv")

# print(data.loc[0])
# print(target.loc[0])

# model = MLPClassifier(random_state=1, max_iter=5000)

# model.fit(data, target.values.ravel())
#print(target.shape)
import pickle

# # #pickle.dump(model, open('rfr_model.sav', 'wb'))

test = np.array([12,8,7,11,9,7,8,12,10,10,0,0,10,10,10,10,0,0,0,10,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,2,0,0,4,4,4,0,0,4,4,4,6,2,1,5,3,1,0,6]).reshape(1,-1)

clf = pickle.load(open('rfr_model.sav', 'rb'))                 
print('Loaded model score:', clf.predict(test))

# print(data[0:1])
# test = clf.predict(data[0:1])

print(len(clf.classes_))
#print(clf.classes_)


# f = open("classes.txt", "a")
# for x in clf.classes_:
#     print("aqui")
#     f.write(x)
#     f.write(' ')
# f.close()






# f = open("weightsBiasOut.txt", "a")
# test = np.array(clf.intercepts_[1])
# for x in test:
#     f.write(" ")
#     f.write(np.array2string(x, formatter={'float_kind':lambda x: "%.5f" % x}))
# f.close()

# f = open("weightsBiasHidden.txt", "a")
# test = np.array(clf.intercepts_[0])
# for x in test:
#     f.write(" ")
#     f.write(np.array2string(x, formatter={'float_kind':lambda x: "%.5f" % x}))
# f.close()

# f = open("weightsOutPut.txt", "a")
# test = np.array(clf.coefs_[1])
# for x in test:
#     f.write(np.array2string(x, formatter={'float_kind':lambda x: "%.5f" % x}))
# f.close()

# f = open("weightsHidden.txt", "a")
# test = np.array(clf.coefs_[0])
# for x in test:
#     f.write(np.array2string(x, formatter={'float_kind':lambda x: "%.5f" % x}))
# f.close()

#cat Game.rec |  grep -o ......$ | sed -e "s/ack //" | sed -e "s/ck //" | sed -e "s/k //" | sed -e "s/ //" > file1
#cat Game.rec | sed 's/\P.*//' > dataChess.csv
#sed -i '1s/^/0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63/' ../dataChess.csv 
#sed -i -e 's/\s\+/,/g' change to space to ,
#sed -i 's/.$//'