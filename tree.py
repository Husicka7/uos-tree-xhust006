from pandas import read_csv
from sklearn import tree
from matplotlib import pyplot
import time

time.sleep(500)

df = read_csv("./data.csv")

print("Your dataset:")
print(df) # print dataset (DataFrame) to stdout

clf = tree.DecisionTreeClassifier(
    max_depth=5 # maximum depth of the tree
)

clf = clf.fit(
    df.drop(columns=[df.columns[-1]]), # dataset without class variable (labels)
    df[df.columns[-1]]                 # class variable (labels)
)

fig = pyplot.figure(
    figsize=(40, 20) # size in hundreds of pixels
)

tree.plot_tree(
    clf,                                    # decision tree
    feature_names=list(df.columns),         # dataset (csv) header
    filled=True,                            # with colors
    class_names=df[df.columns[-1]].unique() # unique labels
)

fig.savefig("decistion_tree.png")


