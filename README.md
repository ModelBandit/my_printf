*This project has been created as part of the 42 curriculum by chchoi.*

### Description
* printf에 대해서 알아보고 가변 인자 함수를 만들어 본다.
* 버퍼 관리 기능 없이 변환 지정자(cspdiuxX)를 처리하여 출력한다.

### Instructions
* make all - 지정한 c파일들을 object파일로 컴파일 한 후 libftprintf.a로 만듬
* make clean - 생성된 object 파일을 전부 제거함.
* make fclean - all 작업을 통해서 생성된 모든 작업 파일을 제거함.
* make re - fclean 수행 후 all 수행

### Resources
* 블로그 포스트

#### AI 사용
이 프로젝트에서 AI는 학습 및 디버깅을 보조하는 도구로 사용하였다.
주요 사용 용도는 다음과 같다.
- 과제 번역 및 해석: 요구사항 및 지침에 대한 전반적인 번역 및 번역 내용에 대한 해석 
- makefile 관련 조사: 문서에서 요구하는 makefile 구성에 있어서 libft의 사용하는데 필요한 기능이나 문법에 대한 조사
- 외부 테스터 검색 및 분석: 검색가능한 42 printf 과제 사설 테스터기를 찾아보고 전반적인 테스트 내용에 대한 정리
- 과제 종합 점검: 과제 완성 후, 미비되거나 잘못된 부분에 대한 점검 및 공방 진행

#### 새로운 정보
- stdarg.h ()
void va_start(va_list ap, last);
type va_arg(va_list ap, type);
void va_end(va_list ap);
void va_copy(va_list dest, va_list src);
가변 인수를 만지는 내장 기능을 호출하는 매크로.

일반적인 함수처럼 ABI(함수 호출 규약)에 따라서 함수가 호출되면 인자들을 레지스터에 올리는 방식을 활용함.
