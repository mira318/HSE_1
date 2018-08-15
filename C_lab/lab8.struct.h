#define THE_STRUCT
struct FIO
{
	char* name;
	char* surename;
	char* secondname;
};
struct Place
{
	long long IDE;
	char* Faculty;
	char* Group;
};
struct Results
{
	int Res[7];
};
typedef struct Student
{
	struct FIO FIO;
	struct Place How;
	struct Results Marks;
}
Student;
