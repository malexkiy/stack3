#include <stack3.hpp>
#include <catch.hpp>

SCENARIO("stack init", "[init]") {
	stack<int> st;
	REQUIRE(st.count() == 0);
}

SCENARIO("stack init object", "[init object]") {
	stack<int> st1;

	st1.push(1);
	st1.push(2);
	st1.push(3);

	stack<int> st2(st1);

	REQUIRE(st1.count() == 3);
	REQUIRE(st2.count() == 3);
}

SCENARIO("stack op=", "[op=]") {
	stack<int> st1;

	st1.push(1);
	st1.push(2);
	st1.push(3);

	stack<int> st2 = st1;

	REQUIRE(st1.count() == 3);
	REQUIRE(st2.count() == 3);
}

SCENARIO("stack push", "[push]") {
	stack<int> st;
	REQUIRE(st.count() == 0);

	st.push(6);
	REQUIRE(st.count() == 1);
	st.push(76);
	REQUIRE(st.count() == 2);
	st.push(-412);
	REQUIRE(st.count() == 3);
}

SCENARIO("stack top", "[top]") {
	stack<int> st;
	REQUIRE(st.count() == 0);

	st.push(6);
	REQUIRE(st.count() == 1);
	REQUIRE(st.top() == 6);

	st.push(76);
	REQUIRE(st.count() == 2);
	REQUIRE(st.top() == 76);

	st.push(-412);
	REQUIRE(st.count() == 3);
	REQUIRE(st.top() == -412);
}

SCENARIO("stack pop", "[pop]") {
	stack<int> st;
	REQUIRE(st.count() == 0);

	st.push(6);
	REQUIRE(st.count() == 1);

	st.push(76);
	REQUIRE(st.count() == 2);

	st.push(-412);
	REQUIRE(st.count() == 3);

	int tmp = st.top();
	st.pop();
	REQUIRE(st.count() == 2);
	REQUIRE(tmp == -412);
	
	tmp = st.top();
	st.pop();
	REQUIRE(st.count() == 1);
	REQUIRE(tmp == 76);
	
	tmp = st.top();
	st.pop();
	REQUIRE(st.count() == 0);
	REQUIRE(tmp == 6);
}