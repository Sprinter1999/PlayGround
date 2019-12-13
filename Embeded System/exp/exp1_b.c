#include "thread.h"

/////////////////////////////////////////////////////////
extern int trace_printf(const char *format, ...);

//void template()
//{
//	while(1){
//		//sync condition
//		while(condition_not_ready()){ //data is not avaliable, key is not pressed/released, time is not out, no input on uart, etc
//			thread_yield();
//		}
//		//handle data
//		do_with_data();
//	}
//}

//user function for test
static int state_num = 0;

//user function for test
static void foo(Thread_ID *to) {
	int i = 0;
	state_num++;
	while (i++ < 1) {
		//ping()
		////调用thread_yeild的时候，调用pick_next()产生被调用的进程指针，根据改指针来进行跳转
		thread_switch_to(*to);
		//pang()
		thread_yield();
	}
}

//main entry
void exp1_b_main() {
	trace_printf("start exp1_b\n");

	threadlib_open();

	Thread_ID th1, th2, th3;
	//create thread
	th1 = thread_create((th_func_t) foo, &th2, "Function 1");
	th2 = thread_create((th_func_t) foo, &th3, "Function 2");
	th3 = thread_create((th_func_t) foo, &th1, "Function 3");

	//start thread
	thread_switch_to(th1);
//	thread_join(th1);
	thread_join(th2);
	thread_join(th3);

	thread_waitall();
	trace_printf("end exp1_b\r\n");
	// trace_printf("end exp1_b\n");
}

