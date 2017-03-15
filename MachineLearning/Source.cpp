#include "Header.h"
#include "stdlib.h"
#include "time.h"

extern "C"
{
	__declspec(dllexport) double *linear_create_model(int inputDimension)
	{
		double* model = new double[inputDimension + 1];
		srand(time(nullptr));
		for (int i = 0; i < inputDimension + 1; i++) {
			int r = rand() % 3;
			if (r == 0) {
				r = -1;
			}
			else if (r == 1) {
				r = 0;
			}
			else {
				r = 1;
			}

			model[i] = r;

		}
		return model;
	}

	void linear_remove_model(double * model)
	{
		delete[] model;
	}


	int linear_fir_classification_rosenblatt(double * model, double * inputs, int inputsSize, int inputSize, double * classes, int iterationNumber, double step)
	{
		/* somme */
		double outputsTmp = model[0];
		for (int j = 0; j < inputSize; j++)
		{
			outputsTmp += inputs[j] * model[j + 1];
		}

		outputsTmp = outputsTmp >= 0 ? 1 : -1;
		/* updateModel */
		if (classes[0] != outputsTmp && step != -1) {

			double constant = step * classes[0];
			for (int i = 0; i < inputSize + 1; i++)
			{
				model[i] = model[i] + constant * inputs[i];
			}
		}

		/* recursive sur l'ensemble des exemples */
		if (inputsSize - inputSize >= inputSize) {
			linear_fir_classification_rosenblatt(model, inputs + inputSize, inputsSize - inputSize, inputSize, classes + 1, iterationNumber, step);
		}

		/* recursive sur apprentissage */
		iterationNumber--;
		if (iterationNumber > 0) {
			linear_fir_classification_rosenblatt(model, inputs, inputsSize, inputSize, classes, iterationNumber, step);
		}

		return 0;
	}

}




/*


int linear_fir_classification_rosenblatt(double * model, double * inputs, int inputsSize, int inputSize, double * classes, double * outputs, int iterationNumber, double step)
{
int mapping = inputsSize / inputSize;

for (int i = 0; i < mapping; i++)
{
double * inputsTmp = new double[inputSize + 1];

for (int j = -1; j < inputSize -1 ; j++)
{
int x = i *inputSize;
if (j == -1) {
inputsTmp[i] = 1;
outputs[i] += model[0];
}
else {
inputsTmp[i] = inputs[x + j];
outputs[i] += inputsTmp[i] * model[x + j];
}
}

if (classes[i] > outputs[i]) {
model = updateModel(model, inputSize + 1, step, classes[i], outputs[i], inputsTmp);
}
}

iterationNumber--;

if (iterationNumber > 0) {
linear_fir_classification_rosenblatt(model, inputs, inputsSize, inputSize, classes, outputs, iterationNumber, step);
}

return 0;
}*/