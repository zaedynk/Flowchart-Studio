#include "Editor.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    FlowchartStudio::Editor^ editor = gcnew FlowchartStudio::Editor();  // Replace 'YourProjectName' with your actual project name
    Application::Run(editor);

    return 0;
}
