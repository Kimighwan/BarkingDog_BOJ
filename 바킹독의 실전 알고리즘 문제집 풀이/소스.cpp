class UnCopyable {
protected:
	UnCopyable() {}
	~UnCopyable() {}
private:
	UnCopyable(const UnCopyable&);
	UnCopyable& operator=(const UnCopyable&);
};

class MyClass : private UnCopyable {

};