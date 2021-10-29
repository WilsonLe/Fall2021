For your progress check-in, you should submit a one to two paragraph summary of your plans and progress so-far on the project. In the summary, you should (at a minimum) describe both the central question(s) you will explore and data sets you intend to use. Also, if you’re working with a partner, you should indicate who you’re working with. All group members should submit a progress check-in individually.

# Progress Checkin

The question we want to answer is that what is the most common adjective in a positive movie review, and in a negative movie review.

To answer the question, we will use a dataset (that contains multiple datasets) of imdb movie review at this link:

https://ai.stanford.edu/~amaas/data/sentiment/

* This dataset has already classified which review is positive or negative, but in folders of txt files. 

* We will use regular expression to match all the txt file names, then iterate throught the txt files.

* While iterating through txt files, we are going to parse the txt files to csv files.

* Then from the csv files, we are going to create pandas DataFrames out of it.

* Then, we define the part of speed of the reviews (which word is noun, adjective, verb, etc.), then count its frequencies. The adjectives with the highest frequency will be considered the most common adjective in a positive/negative review.

* To classify, or, "tag" the part of speech of a body of text, we will use python's NLTK library. We will first tokenize the body of text, then apply NLTK's part of speech tagging method to classify each word's part of speech.

# Get started

folder structure should be as the follwing:

midterm-project
	|
	|---dataset
	|-----test
	|-------neg
	|---------*.txt
	|-------pos
	|---------*.txt
	|-----train
	|-------neg
	|---------*.txt
	|-------pos
	|---------*.txt
	|-----main.ipynb
	|-----neg.csv
	|-----pos.csv
	|-----README.md
