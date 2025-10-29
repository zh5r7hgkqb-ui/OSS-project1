#include<stdio.h>
#define max 100

char c, stack[max], postfix[max];
int  p = 0, top = -1,w, r[max];

int push(char x) {
   if(top == max - 1)return 0;
   else { top++; stack[top] = x; return 1; }
}

char pop() {
   if (top == -1) return 0;
   else { return stack[top--]; 
   }
}
