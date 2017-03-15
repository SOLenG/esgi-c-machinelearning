extern "C"
{
	using namespace std;

	__declspec(dllexport) double *linear_create_model(int inputDimension);
	__declspec(dllexport) void linear_remove_model(double *model);
	__declspec(dllexport) int linear_fit_regression(double *model, double *inputs, int inputsSize, int inputSize, double *outputs, int outputsSize);
	__declspec(dllexport) int linear_fir_classification_rosenblatt(double *model, double *inputs, int inputsSize, int inputSize, double * classes, int iterationNumber, double step);
	//double model, double inputs, int inputsSize, int inputSize, double *outputs, int outputSize, int iterationNumber, double step
	//__declspec(dllexport) double linear_classify(double *model, double *input, int inputSize);
	__declspec(dllexport) double linear_predict(double *model, double *input, int inputSize);
}
