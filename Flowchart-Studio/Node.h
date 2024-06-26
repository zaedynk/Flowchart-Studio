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

    ref class Node {

    public:
        System::Drawing::Point Position;
        System::String^ Text;
        System::Drawing::Size Size;

        Node(System::Drawing::Point pos, System::String^ text) {
            Position = pos;
            Text = text;
            Size = System::Drawing::Size(100, 50); // Example size, adjust as needed
        }

        void Draw(System::Drawing::Graphics^ g) {
            // Draw the rectangle for the node
            g->DrawRectangle(Pens::Black, Drawing::Rectangle(Position, Size));

            // Draw the text centered in the node
            System::Drawing::StringFormat^ format = gcnew System::Drawing::StringFormat();
            format->Alignment = System::Drawing::StringAlignment::Center;
            format->LineAlignment = System::Drawing::StringAlignment::Center;
            g->DrawString(Text, gcnew System::Drawing::Font("Arial", 8), Brushes::Black, RectangleF(Position.X, Position.Y, Size.Width, Size.Height), format);
        }
    };


}