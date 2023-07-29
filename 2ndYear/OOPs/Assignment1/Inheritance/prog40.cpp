class A{
public:
	A(){;}
};

class B{
public:
	B(){;}
};
class C{
public:
	C(){;}
};

class D:public A,public B{
public:
	D(){;}
};
class E:public B,public C{
public:
	E(){;}
};

class F:public D,public E{
public:
	F(){;}
};

int main(){
	return 0;
}

