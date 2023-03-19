#ifndef __foo_H__
#define __foo_H__

class foo
{
public:
	foo();
	foo(const foo &) = default;
	foo(foo &&) = default;
	foo &operator=(const foo &);
	foo &operator=(foo &&);

	~foo();
	int getnum7();
};

#endif // __foo_H__