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
int pushr(int x) {
   if (top == max - 1)return 0;
   else { top++; r[top] = x; return 1; }
}

int popr() {
   if (top == -1) return 0;
   else {
      return r[top--];
   }
}

int ip(char z) {
   if (z == '(') return 0;
   if (z == '+' || z == '-') return 1;
   if (z == '*' || z == '/') return 2;
   return -1;
}

int pre(char g) {
   if (g == '(') {
      push(g); return 0;
   }
   if (g == ')') {
      while (stack[top] != '(') {
         postfix[p++] = pop();
         postfix[p++] = ' ';
      }
      if ( stack[top] == '(') pop();
      return 0;
   }
   
   else if (top == -1 && top==0) push(g);
         else {
            while (top >= 0 && ip(stack[top]) >= ip(g)) {
               postfix[p++] = pop();
               postfix[p++] = ' ';
            }
            push(g);
         }
   return 0;
}

int main() {
   while (1) {
      p = 0;top = -1;w = 0;
      printf("Enter infix>> ");
      while (1) {
         scanf_s("%c", &c);
         if(c=='$') return 0;
         if (c == '\n') break;
         if (c == ' ') {}
         else if ('0' <= c && c <= '9') {
            do {
               postfix[p++] = c;
               if (scanf_s("%c", &c) != 1) break;
            } while (c >= '0' && c <= '9');
               postfix[p++] =' ';
               if (c == '\n')break;
               else if (c == ' ') {}
               else pre(c);
         }
         else pre(c);
      }
      while (top != -1) {
         postfix[p++] = pop();
         if (postfix[p]!=' ')postfix[p++] = ' ';
      }
      postfix[p] = '\0';
