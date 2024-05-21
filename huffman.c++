#include<iostream>
#include<queue>
using namespace std;

//This is the structure of the node containing character and frequency of the character
class ele{
    public:
        char data;
        int freq;
        ele *left,*right;
        ele(char data,int freq){
            this->data=data;
            this->freq=freq;
            left=right=NULL;
        }
};
// this is a comparator used to insert the frequency in the heap in ascending order
class compare{
    public: 
        bool operator()(ele *n1,ele *n2){
            return n1->freq>n2->freq;
        }
};

// This function creates the Huffman tree 
ele* buildTree(vector<ele*> vec){
    priority_queue<ele,vector<ele*>,compare>pq(vec.begin(),vec.end());
    ele *lef,*righ;
    while(pq.size()!=1){
        lef=pq.top();
        pq.pop();
        righ=pq.top();
        pq.pop();
        ele *temp=new ele('$',lef->freq+righ->freq);
        temp->left=lef;
        temp->right=righ;
        pq.push(temp);
    }
    return pq.top();
}

// This code only prints the code of the Character
void finalcode(int arr[],int top){
    for(int i=0;i<top;i++){
        cout<<arr[i];
    }
    cout<<endl; 
}

// This function print Huffman code for every character
void huffmanCode(ele*ans,int arr[],int top){
    if(ans->left){
        arr[top]=0;
        huffmanCode(ans->left,arr,top+1);
    }
    if(ans->right){
        arr[top]=1;
        huffmanCode(ans->right,arr,top+1);
    }
    if(ans->left==NULL && ans->right==NULL){
        cout<<ans->data<<"->";
        finalcode(arr,top);
    }
}

//Helper function to run all the function needed
void printHuffmanCode(vector<ele*>vec){
    ele *ans=buildTree(vec);
    int arr[vec.size()];
    huffmanCode(ans,arr,0);
}
//Driver code
int main(){
    vector<char> character={ 'a', 'b', 'c', 'd', 'e', 'f' }; 
    vector<int> freq={ 5, 9, 12, 13, 16, 45 }; 
    vector<ele*> vec;
    for(int i=0;i<freq.size();i++){
        vec.push_back(new ele(character[i],freq[i]));
    }
    printHuffmanCode(vec);
}