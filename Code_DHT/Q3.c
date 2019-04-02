/*
CMPT-371 
Firas Fakih
Question 3, Project 1
301347333
ffakih@sfu.ca
Programming Language : C
*/


#include <stdio.h>


//Keeps Nodes in a circle
void appendNode(int node,int S,int tablesize,int A[]){
	int i,rightNode;
	rightNode = node;
	for(i=0;i<S;++i){
		if(A[rightNode]==rightNode)
			break;
		A[rightNode] = node;
		rightNode = indexLoop(S,rightNode-1);
	}
	
	return;
}
int indexLoop(int S,int x){
	if(x>=S)
		x-=S;
	else if(x<0)
		x+=S;
	return x;
}



int main(int argc, char **argv){
	int i;
	char separate;
	int S,N,M,node,key;
	int successCol[511],joined[511];
	FILE *fin,*fout;
	//511 because in the question it specifies that max size is 2^k-1 where k<10 , so 2^9 -1 is 511

	//If Less than 3 arguments
	if(argc != 3){
		printf("Please use format ./a.out XXX.in XXX.out");
		return 0;
	}
	
	//read data from file
	fin = fopen(argv[1],"r");
	fout = fopen(argv[2],"w");
	fscanf(fin,"%d %d %d",&S,&N,&M);
	++S;
	

	//initialization
	for(i=0;i<S;++i){
		successCol[i] = 0;
	}
	for(i=0;i<N;++i){
		fscanf(fin,"%d%c",joined+i,&separate);
		appendNode(joined[i],S,S,successCol);
	}

	//read keys
	for(i=0;i<M;++i){
		fscanf(fin,"%d%c",&key,&separate);   
		fprintf(fout,"%d\n", successCol[key]); // print key 
		fprintf(fout,"0 %d %d\n", successCol[key]+1, successCol[successCol[key]+1]);   // 0 1 2 Is default
		fprintf(fout,"1 %d %d\n", successCol[key]+2, successCol[successCol[key]+2]);
		fprintf(fout,"2 %d %d\n", successCol[key]+4, successCol[successCol[key]+4]);
		
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
