from sklearn.neural_network import MLPClassifier
import pandas as pd
import numpy as np

data = pd.read_csv("/home/vantunes/ChessGame/HalfData.csv")
# target = pd.read_csv("/home/vantunes/ChessGame/HalfTarget.csv")

# model = MLPClassifier(random_state=1, hidden_layer_sizes=(1024,), max_iter=1000)

# print(data.values.shape)
# print(target.values.shape)

# model.fit(data.values, target.values.ravel())

def relu(x):
    return(np.maximum(0, x))

test = data
import pickle

#anp.array([1,2,3])


#pickle.dump(model, open('rfr_model.sav', 'wb'))

clf = pickle.load(open('rfr_model.sav', 'rb'))

test = np.array([12,8,7,11,9,7,8,12,10,10,10,10,10,10,10,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,6,2,1,5,3,1,2,6]).reshape(1, -1)

bias = clf.intercepts_
HiddenBias = bias[0]
OutPutBias = bias[1]
HiddenWeights = clf.coefs_[0]
OutPutWeights = clf.coefs_[1]
 
# #Forward propagation
# print(HiddenWeights[0][0])
# print(HiddenBias[0])

forward = np.matmul(test, HiddenWeights) + HiddenBias
forward = relu(forward)
forward = np.matmul(forward, OutPutWeights) + OutPutBias
 
print(np.max(forward))

# #Getting the max value from the outPut Layer
# #Saving in a list to compare with the original algorithm
# my_predictions = np.argmax(forward)
 
# #Saving in a list to compare with the copy algorithm
# # test_y = clf.predict(data.value)
# # predic = []
# # for i in test_y:
# #     predic.append(i)

# print(clf.predict(test))
# print(clf.classes_[my_predictions])
 
 
# print("My algorithm predicions")
# print(my_predictions)
# print("Sklearn Predictions ")
# print(predic)


# f = open("classes.txt", "a")
# for x in clf.classes_:
#     f.write(x)
#     f.write(' ')
# f.close()

# np.savetxt("weightsBiasHidden.txt", clf.intercepts_[0], delimiter=',')
# np.savetxt("weightsBiasOut.txt", clf.intercepts_[1], delimiter=',')
# np.savetxt('weightsHidden.txt', clf.coefs_[0], delimiter=',')
# np.savetxt('weightsOut.txt', clf.coefs_[1], delimiter=',') 


#cat Game.rec |  grep -o ......$ | sed -e "s/ack //" | sed -e "s/ck //" | sed -e "s/k //" | sed -e "s/ //" > file1
#cat Game.rec | sed 's/\P.*//' > dataChess.csv
#sed -i '1s/^/0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63/' ../dataChess.csv 
#sed -i -e 's/\s\+/,/g' change to space to ,
#sed -i 's/.$//'