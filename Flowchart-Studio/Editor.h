#pragma once
#include <string>
#include <regex>
#include "Node.h"
namespace FlowchartStudio {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Collections::Generic;

    using namespace System::Resources;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Text::RegularExpressions;
    using namespace System::IO;
    using namespace System::Windows;
    using namespace System::Windows::Forms;

    

    public ref class Editor : public System::Windows::Forms::Form {
    public:
        Editor(void) {
            InitializeComponent();
            nodes = gcnew System::Collections::Generic::List<Node^>(false);

            this->Flowchart->MouseDown += gcnew MouseEventHandler(this, &Editor::Flowchart_MouseDown);
            this->Flowchart->MouseMove += gcnew MouseEventHandler(this, &Editor::Flowchart_MouseMove);
            this->Flowchart->MouseUp += gcnew MouseEventHandler(this, &Editor::Flowchart_MouseUp);
        }

    protected:
        ~Editor() {
            if (Components) {
                delete Components;
            }
        }

    private: System::ComponentModel::Container^ Components;

    private: Panel^ Flowchart;
    private: RichTextBox^ Preview;
    private: TreeView^ Hierarchy;
    private: MenuStrip^ MenuBar;
    private: ToolStripMenuItem^ MenuBar_Project;
    private: ToolStripMenuItem^ MenuBar_Project_ImportDirectory;
    private: FolderBrowserDialog^ FileExplorerDialog;
    private: System::Windows::Forms::Label^ HierarchyLabel;
    private: System::Windows::Forms::Label^ FlowchartLabel;
    private: System::Windows::Forms::SplitContainer^ splitContainer2;
    private: System::Windows::Forms::SplitContainer^ splitContainer1;
    private: System::Windows::Forms::Label^ PreviewLabel;
    private: System::Windows::Forms::ContextMenuStrip^ flowchartContextMenu;
    private: System::ComponentModel::IContainer^ components;
    private: System::Windows::Forms::ToolStripMenuItem^ addNodeMenuItem;
    public:  System::Collections::Generic::List<Node^>^ nodes;
#pragma region Windows Form Designer generated code
           void InitializeComponent(void) {
               this->components = (gcnew System::ComponentModel::Container());
               this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
               this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
               this->Hierarchy = (gcnew System::Windows::Forms::TreeView());
               this->Flowchart = (gcnew System::Windows::Forms::Panel());
               this->flowchartContextMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
               this->addNodeMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->Preview = (gcnew System::Windows::Forms::RichTextBox());
               this->PreviewLabel = (gcnew System::Windows::Forms::Label());
               this->MenuBar = (gcnew System::Windows::Forms::MenuStrip());
               this->MenuBar_Project = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->MenuBar_Project_ImportDirectory = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->FileExplorerDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
               this->HierarchyLabel = (gcnew System::Windows::Forms::Label());
               this->FlowchartLabel = (gcnew System::Windows::Forms::Label());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
               this->splitContainer2->Panel1->SuspendLayout();
               this->splitContainer2->Panel2->SuspendLayout();
               this->splitContainer2->SuspendLayout();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
               this->splitContainer1->Panel1->SuspendLayout();
               this->splitContainer1->Panel2->SuspendLayout();
               this->splitContainer1->SuspendLayout();
               this->flowchartContextMenu->SuspendLayout();
               this->MenuBar->SuspendLayout();
               this->SuspendLayout();
               // 
               // splitContainer2
               // 
               this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
               this->splitContainer2->Location = System::Drawing::Point(0, 64);
               this->splitContainer2->Name = L"splitContainer2";
               // 
               // splitContainer2.Panel1
               // 
               this->splitContainer2->Panel1->Controls->Add(this->splitContainer1);
               // 
               // splitContainer2.Panel2
               // 
               this->splitContainer2->Panel2->Controls->Add(this->Preview);
               this->splitContainer2->Size = System::Drawing::Size(1200, 536);
               this->splitContainer2->SplitterDistance = 744;
               this->splitContainer2->TabIndex = 4;
               this->splitContainer2->SplitterMoved += gcnew System::Windows::Forms::SplitterEventHandler(this, &Editor::SplitContainer2_Update);
               // 
               // splitContainer1
               // 
               this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
               this->splitContainer1->Location = System::Drawing::Point(0, 0);
               this->splitContainer1->Name = L"splitContainer1";
               // 
               // splitContainer1.Panel1
               // 
               this->splitContainer1->Panel1->Controls->Add(this->Hierarchy);
               // 
               // splitContainer1.Panel2
               // 
               this->splitContainer1->Panel2->Controls->Add(this->Flowchart);
               this->splitContainer1->Size = System::Drawing::Size(744, 536);
               this->splitContainer1->SplitterDistance = 168;
               this->splitContainer1->TabIndex = 0;
               this->splitContainer1->SplitterMoved += gcnew System::Windows::Forms::SplitterEventHandler(this, &Editor::SplitContainer1_Update);
               // 
               // Hierarchy
               // 
               this->Hierarchy->BackColor = System::Drawing::Color::GhostWhite;
               this->Hierarchy->Dock = System::Windows::Forms::DockStyle::Fill;
               this->Hierarchy->Location = System::Drawing::Point(0, 0);
               this->Hierarchy->Name = L"Hierarchy";
               this->Hierarchy->Size = System::Drawing::Size(168, 536);
               this->Hierarchy->TabIndex = 2;
               this->Hierarchy->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Editor::Hierarchy_Select);
               // 
               // Flowchart
               // 
               this->Flowchart->BackColor = System::Drawing::Color::OldLace;
               this->Flowchart->ContextMenuStrip = this->flowchartContextMenu;
               this->Flowchart->Dock = System::Windows::Forms::DockStyle::Fill;
               this->Flowchart->Location = System::Drawing::Point(0, 0);
               this->Flowchart->Name = L"Flowchart";
               this->Flowchart->Size = System::Drawing::Size(572, 536);
               this->Flowchart->TabIndex = 4;
               this->Flowchart->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Editor::Flowchart_Paint);
               this->Flowchart->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Editor::Flowchart_RightClick);
               // 
               // flowchartContextMenu
               // 
               this->flowchartContextMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->addNodeMenuItem });
               this->flowchartContextMenu->Name = L"flowchartContextMenu";
               this->flowchartContextMenu->Size = System::Drawing::Size(129, 26);
               // 
               // addNodeMenuItem
               // 
               this->addNodeMenuItem->Name = L"addNodeMenuItem";
               this->addNodeMenuItem->Size = System::Drawing::Size(128, 22);
               this->addNodeMenuItem->Text = L"Add Node";
               this->addNodeMenuItem->Click += gcnew System::EventHandler(this, &Editor::AddNode_Click);
               // 
               // Preview
               // 
               this->Preview->BackColor = System::Drawing::Color::GhostWhite;
               this->Preview->Dock = System::Windows::Forms::DockStyle::Fill;
               this->Preview->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
               this->Preview->Location = System::Drawing::Point(0, 0);
               this->Preview->Name = L"Preview";
               this->Preview->ReadOnly = true;
               this->Preview->Size = System::Drawing::Size(452, 536);
               this->Preview->TabIndex = 6;
               this->Preview->Text = L"";
               this->Preview->TextChanged += gcnew System::EventHandler(this, &Editor::Preview_Changed);
               // 
               // PreviewLabel
               // 
               this->PreviewLabel->AutoSize = true;
               this->PreviewLabel->Location = System::Drawing::Point(745, 49);
               this->PreviewLabel->Name = L"PreviewLabel";
               this->PreviewLabel->Size = System::Drawing::Size(67, 13);
               this->PreviewLabel->TabIndex = 7;
               this->PreviewLabel->Text = L"C++ Preview";
               // 
               // MenuBar
               // 
               this->MenuBar->Dock = System::Windows::Forms::DockStyle::None;
               this->MenuBar->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->MenuBar_Project });
               this->MenuBar->Location = System::Drawing::Point(0, 2);
               this->MenuBar->Name = L"MenuBar";
               this->MenuBar->Size = System::Drawing::Size(64, 24);
               this->MenuBar->TabIndex = 0;
               // 
               // MenuBar_Project
               // 
               this->MenuBar_Project->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->MenuBar_Project_ImportDirectory });
               this->MenuBar_Project->Name = L"MenuBar_Project";
               this->MenuBar_Project->Size = System::Drawing::Size(56, 20);
               this->MenuBar_Project->Text = L"&Project";
               // 
               // MenuBar_Project_ImportDirectory
               // 
               this->MenuBar_Project_ImportDirectory->Name = L"MenuBar_Project_ImportDirectory";
               this->MenuBar_Project_ImportDirectory->Size = System::Drawing::Size(161, 22);
               this->MenuBar_Project_ImportDirectory->Text = L"&Import Directory";
               this->MenuBar_Project_ImportDirectory->Click += gcnew System::EventHandler(this, &Editor::MenuBar_Project_ImportDirectory_Click);
               // 
               // HierarchyLabel
               // 
               this->HierarchyLabel->Location = System::Drawing::Point(3, 49);
               this->HierarchyLabel->Name = L"HierarchyLabel";
               this->HierarchyLabel->Size = System::Drawing::Size(150, 12);
               this->HierarchyLabel->TabIndex = 1;
               this->HierarchyLabel->Text = L"Hierarchy";
               // 
               // FlowchartLabel
               // 
               this->FlowchartLabel->Location = System::Drawing::Point(425, 49);
               this->FlowchartLabel->Name = L"FlowchartLabel";
               this->FlowchartLabel->Size = System::Drawing::Size(100, 12);
               this->FlowchartLabel->TabIndex = 3;
               this->FlowchartLabel->Text = L"Flowchart";
               // 
               // Editor
               // 
               this->BackColor = System::Drawing::SystemColors::Menu;
               this->ClientSize = System::Drawing::Size(1200, 600);
               this->Controls->Add(this->FlowchartLabel);
               this->Controls->Add(this->HierarchyLabel);
               this->Controls->Add(this->MenuBar);
               this->Controls->Add(this->splitContainer2);
               this->Controls->Add(this->PreviewLabel);
               this->Name = L"Editor";
               this->Padding = System::Windows::Forms::Padding(0, 64, 0, 0);
               this->Text = L"Flowchart Studio";
               this->Load += gcnew System::EventHandler(this, &Editor::Editor_Load);
               this->splitContainer2->Panel1->ResumeLayout(false);
               this->splitContainer2->Panel2->ResumeLayout(false);
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
               this->splitContainer2->ResumeLayout(false);
               this->splitContainer1->Panel1->ResumeLayout(false);
               this->splitContainer1->Panel2->ResumeLayout(false);
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
               this->splitContainer1->ResumeLayout(false);
               this->flowchartContextMenu->ResumeLayout(false);
               this->MenuBar->ResumeLayout(false);
               this->MenuBar->PerformLayout();
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion
    private:
        private: bool isDragging = false;
        private: System::Drawing::Point lastMousePosition;

        /* Splitters */
        
        void SplitContainer2_Update(Object^ sender, SplitterEventArgs^ e);       // Event handler for when SplitContainer2's splitter is moved
        void SplitContainer1_Update(Object^ sender, SplitterEventArgs^ e);       // Event handler for when the SplitContainer1's splitter is moved
        void SplitContainer_MoveLabel();                                         // Custom function for dynamic repositioning of the "Flowchart" label

        /* Flowchart */
        void Flowchart_MouseDown(Object^ sender, MouseEventArgs^ e);
        void Flowchart_MouseMove(Object^ sender, MouseEventArgs^ e);
        void Flowchart_MouseUp(Object^ sender, MouseEventArgs^ e);
        void Flowchart_RightClick(Object^ sender, MouseEventArgs^ e);        // Event handler for right-click on Flowchart panel
        void CreateFlowchartNodes();
        void AddFlowchartNode(String^ nodeText, int depth);
        void Flowchart_Paint(Object^ sender, PaintEventArgs^ e);

        // Functional - Contenxt Menu Items
        void AddNode_Click(Object^ sender, EventArgs^ e);        // Event handler for "Add Node" menu item click



        /* Hierarchy */
        void  Hierarchy_Select(Object^ sender, TreeViewEventArgs^ e);
        void ListFiles(TreeNodeCollection^ nodes, String^ path);         // Imported Files




        /* MenuBar - Project  */
        void MenuBar_Project_ImportDirectory_Click(Object^ sender, EventArgs^ e);




        /* Preview */
        System::Void Preview_Changed(System::Object^ sender, System::EventArgs^ e);







    private: System::Void Editor_Load(System::Object^ sender, System::EventArgs^ e) {
    }
};




}
