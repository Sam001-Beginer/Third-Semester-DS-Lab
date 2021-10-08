#include <bits/stdc++.h>

using namespace std;
	
	class Stack{

	public:
	char data;
	Stack *next;
};
int  isEmpty(Stack *top){
	if(top==NULL)
	return 1;
	else
	return 0;
}
void push(Stack **top,char new_data){
	Stack *temp=new Stack();
	if(temp==NULL){
		cout<<"Stack overflow"<<endl;
		return;
	}
	temp->data=new_data;
	temp->next=*top;
	*top=temp;
}
char pop(Stack** root){
    if (isEmpty(*root))
        return 0;
    Stack* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    delete(temp);
 
    return popped;
}
char stackTop(Stack *top){
	return top->data;
}

	Stack* top=NULL;
bool CheckParanthesis(string str){
	
	char x;
	for(int i=0;i<str.length();i++) {
		
		if (str[i] == '(' || str[i] == '['
            || str[i] == '{'){
			
			push(&top,str[i]);
			continue;
		}
		
		if(isEmpty(top))
		return false;
		
		 switch (str[i]) {
        case ')':
             
            // Store the top element in a
            x = stackTop(top);
            pop(&top);
            if (x == '{' || x == '[')
                return false;
            break;
 
        case '}':
 
            // Store the top element in b
            x = stackTop(top);
            pop(&top);
            if (x == '(' || x == '[')
                return false;
            break;
 
        case ']':
 
            // Store the top element in c
            x = stackTop(top);
            pop(&top);
            if (x == '(' || x == '{')
                return false;
            break;
        }
	}
	
	return isEmpty(top);
	}




int main(){
string str;
cout<<"Enter an Equation"<<endl;
getline(cin,str);
CheckParanthesis(str)?cout<<"Balanced Paranthesis":cout<<"Unbalanced Parenthesis"<<endl;
return 0;
}

