#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows) 
{
    int n = stalls.size();
    int cntCows = 1;
    int last = stalls[0];
    for (int i = 1; i < n; i++) 
    {
        if (stalls[i] - last >= dist) 
        {
            cntCows++; //place next cow.
            last = stalls[i]; //update the last location.
        }
        if (cntCows >= cows) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k) 
{
    int n = stalls.size();

    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true) 
        {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}





Imports:

> `from sklearn.feature_extraction.text import CountVectorizer`: This line imports the `CountVectorizer` class from the `scikit-learn` library. This class is used to convert text data into numerical features, which are then used by machine learning models for classification tasks.
> `from sklearn.naive_bayes import MultinomialNB, GaussianNB`: This line imports the `MultinomialNB` and `GaussianNB` classes from the `scikit-learn` library. These classes are used to implement two different types of Naive Bayes classifiers for spam email detection.
> `from sklearn.metrics import accuracy_score, confusion_matrix, classification_report`: This line imports several evaluation metrics from the `scikit-learn` library. These metrics are used to assess the performance of the trained classifiers.

Data Loading and Splitting:

> `data = pd.read_csv('C:/Users/verma/Downloads/emailsSPAM.csv')`: This line reads the CSV file containing email data into a pandas DataFrame object named `data`.
> `train_test_split`: This function splits the data into separate training and testing sets. The default split ratio is 80% training data and 20% testing data.

Feature Engineering:

> `CountVectorizer()`: This line creates a new `CountVectorizer` object.
> `fit_transform`: This method is applied to the training data. It first analyzes the data to learn the vocabulary of words and then transforms each email into a sparse matrix that represents the number of occurrences of each word in the vocabulary.
> `transform`: This method uses the same `CountVectorizer` object to transform the test data into a similar sparse matrix based on the vocabulary already learned from the training data.

Model Training:

> `MultinomialNB()`: This line creates a new `MultinomialNB` object, which represents a Multinomial Naive Bayes classifier.
> `fit`: This method trains the `MultinomialNB` classifier on the training data. The classifier learns the statistical relationships between words and spam labels to predict the spam probability of new emails.
> `GaussianNB()`: This line creates a new `GaussianNB` object, which represents a Gaussian Naive Bayes classifier.
> `fit`: This method trains the `GaussianNB` classifier on the training data. This type of classifier assumes that the features follow a normal distribution and estimates the probability density function for each class (spam or not spam) to make predictions.

Prediction and Evaluation:

> `predict`: This method applies both trained classifiers to the test data and generates predictions for each email, indicating whether it is classified as spam or not spam.
> `accuracy_score`: This metric calculates the overall accuracy of the classifier, which is the percentage of correctly predicted emails.
> `confusion_matrix`: This metric provides a detailed breakdown of the true positives, true negatives, false positives, and false negatives for each class.
> `classification_report`: This metric provides additional information about the classifier's performance, including precision, recall, and F1 score for each class.

Result Reporting:

> The code finally displays the accuracy, confusion matrix, and classification report for both Multinomial Naive Bayes and Gaussian Naive Bayes classifiers, allowing for a comprehensive evaluation of their performance on the spam email detection task.
