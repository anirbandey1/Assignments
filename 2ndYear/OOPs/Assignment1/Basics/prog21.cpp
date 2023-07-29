#include <iostream>
#include <stdlib.h>
using namespace std;

class Vector{
	int n;
	int *a;

public:
Vector(){
	n=0;
	a=NULL;
}
Vector(int sz){
	n=sz;
	a=new int[n];
}
Vector(const Vector &vec){
	n=vec.n;
	free(a);
	a=new int[n];
	
	for(int i=0;i<n;i++)
	{
		a[i]=vec.a[i];
	}
}
void input(){
	cout<<"Enter the Size of Array : ";
	cin>>n;
	a=new int[n];
	cout<<"Enter the Array : ";

	for(int i=0;i<n;i++){
		cin>>a[i];	
	}
}

void print(){
	cout<<"Array of size "<<n<<" : ";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

Vector operator + (const Vector &vec2){
	int  maxi= n>vec2.n ? n : vec2.n;
	Vector vec3;
	vec3.n=maxi;
	vec3.a=new int[vec3.n];
	
	for(int i=0;i<vec3.n;i++)
	{
		int el=0;
		if(i<n)el+=a[i];
		if(i<vec2.n)el+=vec2.a[i];

		vec3.a[i]=el;
	}

	return vec3;
}
Vector operator - (const Vector &vec2){
        Vector vec3;
        vec3.n=n;;
        vec3.a=(int*)calloc(vec3.n,sizeof(int));

        for(int i=0;i<vec3.n;i++)
        {
                int el=0;
                el+=a[i];
                if(i<vec2.n)el-=vec2.a[i];

                vec3.a[i]=el;
        }

        return vec3;
}

bool operator == (const Vector &vec2){
	if(n!=vec2.n)return false;
	
	for(int  i=0;i<n;i++){
		if(a[i]!=vec2.a[i]){
			return false;
		}
	}
	return true;
}

bool operator > (const Vector &vec){

	if(n>vec.n)return true;
	else if(n<vec.n)return false;

	for(int i=0;i<n;i++)
	{
		if(a[i]>vec.a[i])
			return true;
		else if(a[i]<vec.a[i])
			return false;
	}
	return false;
}

bool operator < (const Vector &vec){

	if(n<vec.n)return true;
	else if(n>vec.n)return false;


	for(int i=0;i<n;i++)
	{
		if(a[i]<vec.a[i])
			return true;
		else if(a[i]>vec.a[i])
			return false;
	}
	return false;
}

};

int main(){

	Vector vec1,vec2;
	cout<<"First array"<<endl;
	vec1.input();
	cout<<"Second array"<<endl;
	vec2.input();

	vec1.print();
	vec2.print();
	
	if(vec1==vec2)
		cout<<"The two vectors are EQUAL"<<endl;
	else if(vec1<vec2)
		cout<<"Vector 1 is smaller than Vector 2"<<endl;
	else if(vec1>vec2)
		cout<<"Vector 1 is greater than Vector 2"<<endl;

	Vector vec3=vec1+vec2;
	cout<<"Addition Vector : "<<endl;
	vec3.print();

	Vector vec4=vec1-vec2;
        cout<<"Difference Vector : "<<endl;
        vec4.print();

	
	
	return 0;

}
