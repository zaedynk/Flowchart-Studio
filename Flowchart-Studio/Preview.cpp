#include "Editor.h"

/* Preview - Code  */
System::Void FlowchartStudio::Editor::Preview_Changed(System::Object^ sender, System::EventArgs^ e) {
    CreateFlowchartNodes();
}