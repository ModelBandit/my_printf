*This project has been created as part of the 42 curriculum by chchoi.*

### Description
* C

### Instructions
* make all - c파일들을 object파일로 컴파일 한 후 libftprintf.a로 만듬
* make clean - object 파일을 전부 제거함.
* make fclean - all 작업을 통해서 생성된 모든 작업 파일을 제거함.
* make re - fclean 수행 후 all 수행

### Resources
* man function

#### AI 사용
이 프로젝트에서 AI는 학습 및 디버깅을 보조하는 도구로 사용하였다.
주요 사용 용도는 다음과 같다.
- C

#### 새로운 정보
- stdarg.h ()
void va_start(va_list ap, last);
type va_arg(va_list ap, type);
void va_end(va_list ap);
void va_copy(va_list dest, va_list src);
가변 인수를 만지는 내장 기능을 호출하는 매크로.