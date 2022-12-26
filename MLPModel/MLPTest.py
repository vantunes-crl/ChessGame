from sklearn.neural_network import MLPClassifier
from sklearn.model_selection import train_test_split
from sklearn.datasets import load_iris
import numpy as np
from sklearn.metrics import accuracy_score
 
#Init iris data and targets
iris_data = load_iris()
y = iris_data.target
X = iris_data.data
 
#Split the data 20% for test
train_X, test_X, train_y, test_y = train_test_split(X, y, test_size=0.2, random_state=42)
 
#Fit the MLP with 5 hidden neurons
clf = MLPClassifier(hidden_layer_sizes=5, max_iter=5000)
clf.fit(train_X, train_y)
 
#Predict list from splitted test
y_pred = clf.predict(test_X)
 
#Check Accuracy Score
acc = accuracy_score(test_y, y_pred)
 
#Getting Weights
bias = clf.intercepts_
HiddenBias = bias[0]
OutPutBias = bias[1]
HiddenWeights = clf.coefs_[0]
OutPutWeights = clf.coefs_[1]
 
#Forward propagation
forward = np.matmul(test_X, HiddenWeights) + HiddenBias
forward = np.matmul(forward, OutPutWeights) + OutPutBias
 
#Getting the max value from the outPut Layer
#Saving in a list to compare with the original algorithm
my_predictions = []
for i in forward:
    my_predictions.append(max(enumerate(i), key=lambda x:x[1])[0])
 
#Saving in a list to compare with the copy algorithm
predic = []
for i in test_y:
    predic.append(i)
 
print(forward)
 
 
print("My algorithm predicions")
print(my_predictions)
print("Sklearn Predictions ")
print(predic)
print("Accuracy Score: {}".format(acc))