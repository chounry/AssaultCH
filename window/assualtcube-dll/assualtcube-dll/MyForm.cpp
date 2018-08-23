#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

using namespace assualtcubedll;
int UImain()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	MyForm^ NewUi = gcnew MyForm();
	Application::Run(NewUi);
	return 1;
}

//[STAThreadAttribute]
//void Main(array<String^>^ args) {
//	Application::EnableVisualStyles();
//	Application::SetCompatibleTextRenderingDefault(false);
//	assualtcubedll::MyForm form;
//	Application::Run(%form);
//}
