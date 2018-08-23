#pragma once
#include<Windows.h>
#include<ctime>
#include<string>
#pragma comment(lib, "user32.lib")
//#include <tlhelp32.h>
//#include <tchar.h>

namespace assualtcubedll {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	std::string Nops[] = {
		"\x90",
		"\x90\x90",
		"\x90\x90\x90",
		"\x90\x90\x90\x90"
	};

	bool ammoStatus;
	char ammoOpc[] = "\x90\x90";
	char ammoDefaultOpc[] = "\xFF\x0E";
	DWORD ammoAddress = 0x4637e9;

	
	bool healthStatus;
	char healtValue[] = "\x39\x50";
	char healthDefaultValue[] = "\x64\x0";
	DWORD healthAddress = 0x400000 + 0x00109B74;
	DWORD addressToWrite;
	DWORD healthOffsets[] = { 0xf8 };

	bool rFireStatus;
	char rFireOpc[] = "\x90\x90";
	char rFireDefaultOpc[] = "\x89\x0A";
	DWORD rFireAddress = 0x4637e4;


	bool recoilStatus;
	char recoilOpc[];
	std::string recoilDefaultOpc[] = {
		"\x8B\x16",
		"\x8B\x52\x14",
		"\x50",
		"\x80\x4C\x24\x1C",
		"\x51",
		"\x8B\xCE",
		"\xFF\xD2"
	};
	DWORD recoilAddress[] = {0x463781,0x463783,0x463786,0x463787,0x46378b,0x46378c,0x46378e};
	int noOfByte[] = { 2,3,1,4,1,2,2 };


	bool autoGunStatus;
	char autoGunOpc[] = "\xEB\x09";
	char autoGunDefaultOpc[] = "\x75\x09";
	DWORD autoGunAddress = 0x463716;

	int onePressTMR = clock();
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  assultcube_title;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  freezeAmmoLB;
	private: System::Windows::Forms::Label^  freezeHealthLB;
	private: System::Windows::Forms::Label^  rapidFireLB;
	private: System::Windows::Forms::Label^  recoilLB;
	private: System::Windows::Forms::Label^  autoGunLb;
	private: System::Windows::Forms::Timer^  timer;

	private: System::ComponentModel::IContainer^  components;





	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->assultcube_title = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->freezeAmmoLB = (gcnew System::Windows::Forms::Label());
			this->freezeHealthLB = (gcnew System::Windows::Forms::Label());
			this->rapidFireLB = (gcnew System::Windows::Forms::Label());
			this->recoilLB = (gcnew System::Windows::Forms::Label());
			this->autoGunLb = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// assultcube_title
			// 
			this->assultcube_title->AutoSize = true;
			this->assultcube_title->BackColor = System::Drawing::Color::Black;
			this->assultcube_title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->assultcube_title->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->assultcube_title->Location = System::Drawing::Point(75, 9);
			this->assultcube_title->Name = L"assultcube_title";
			this->assultcube_title->Size = System::Drawing::Size(227, 37);
			this->assultcube_title->TabIndex = 0;
			this->assultcube_title->Text = L"AssultCube Dll";
			this->assultcube_title->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(12, 46);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(327, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"DLL Status : Injected Sucessfully";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_1);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(12, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(175, 24);
			this->label2->TabIndex = 2;
			this->label2->Text = L"[F1] Freeze ammo :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Black;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->Location = System::Drawing::Point(13, 152);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(136, 24);
			this->label3->TabIndex = 3;
			this->label3->Text = L"[F3] Rapid fire :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Black;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label4->Location = System::Drawing::Point(12, 116);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(176, 24);
			this->label4->TabIndex = 3;
			this->label4->Text = L"[F2] Freeze Health :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Black;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label5->Location = System::Drawing::Point(12, 188);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(215, 24);
			this->label5->TabIndex = 4;
			this->label5->Text = L"[F4] No recoil kick back :";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Black;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label6->Location = System::Drawing::Point(12, 224);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(201, 24);
			this->label6->TabIndex = 5;
			this->label6->Text = L"[F5] All gun automatic :";
			// 
			// freezeAmmoLB
			// 
			this->freezeAmmoLB->AutoSize = true;
			this->freezeAmmoLB->BackColor = System::Drawing::Color::Black;
			this->freezeAmmoLB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->freezeAmmoLB->ForeColor = System::Drawing::Color::Red;
			this->freezeAmmoLB->Location = System::Drawing::Point(193, 82);
			this->freezeAmmoLB->Name = L"freezeAmmoLB";
			this->freezeAmmoLB->Size = System::Drawing::Size(49, 24);
			this->freezeAmmoLB->TabIndex = 6;
			this->freezeAmmoLB->Text = L"OFF";
			// 
			// freezeHealthLB
			// 
			this->freezeHealthLB->AutoSize = true;
			this->freezeHealthLB->BackColor = System::Drawing::Color::Black;
			this->freezeHealthLB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->freezeHealthLB->ForeColor = System::Drawing::Color::Red;
			this->freezeHealthLB->Location = System::Drawing::Point(193, 116);
			this->freezeHealthLB->Name = L"freezeHealthLB";
			this->freezeHealthLB->Size = System::Drawing::Size(49, 24);
			this->freezeHealthLB->TabIndex = 7;
			this->freezeHealthLB->Text = L"OFF";
			// 
			// rapidFireLB
			// 
			this->rapidFireLB->AutoSize = true;
			this->rapidFireLB->BackColor = System::Drawing::Color::Black;
			this->rapidFireLB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rapidFireLB->ForeColor = System::Drawing::Color::Red;
			this->rapidFireLB->Location = System::Drawing::Point(155, 152);
			this->rapidFireLB->Name = L"rapidFireLB";
			this->rapidFireLB->Size = System::Drawing::Size(49, 24);
			this->rapidFireLB->TabIndex = 8;
			this->rapidFireLB->Text = L"OFF";
			// 
			// recoilLB
			// 
			this->recoilLB->AutoSize = true;
			this->recoilLB->BackColor = System::Drawing::Color::Black;
			this->recoilLB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->recoilLB->ForeColor = System::Drawing::Color::Red;
			this->recoilLB->Location = System::Drawing::Point(233, 188);
			this->recoilLB->Name = L"recoilLB";
			this->recoilLB->Size = System::Drawing::Size(49, 24);
			this->recoilLB->TabIndex = 9;
			this->recoilLB->Text = L"OFF";
			// 
			// autoGunLb
			// 
			this->autoGunLb->AutoSize = true;
			this->autoGunLb->BackColor = System::Drawing::Color::Black;
			this->autoGunLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->autoGunLb->ForeColor = System::Drawing::Color::Red;
			this->autoGunLb->Location = System::Drawing::Point(219, 224);
			this->autoGunLb->Name = L"autoGunLb";
			this->autoGunLb->Size = System::Drawing::Size(49, 24);
			this->autoGunLb->TabIndex = 10;
			this->autoGunLb->Text = L"OFF";
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(368, 264);
			this->Controls->Add(this->autoGunLb);
			this->Controls->Add(this->recoilLB);
			this->Controls->Add(this->rapidFireLB);
			this->Controls->Add(this->freezeHealthLB);
			this->Controls->Add(this->freezeAmmoLB);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->assultcube_title);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Name = L"MyForm";
			this->Text = L"AssualtCube Injector";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (clock() - onePressTMR > 400) {

			/// ========= Ammo
			if (GetAsyncKeyState(VK_F1)) {
				onePressTMR = clock();
				ammoStatus = !ammoStatus;
				if (ammoStatus) {
					freezeAmmoLB->Text = "ON";
					writeToMemory(ammoAddress, ammoOpc, 2);
				}
				else {
					freezeAmmoLB->Text = "OFF";
					writeToMemory(ammoAddress, ammoDefaultOpc, 2);
				}
			}

			/// ===== Health
			if (GetAsyncKeyState(VK_F2)) {
				onePressTMR = clock();
				healthStatus = !healthStatus;
				addressToWrite = FindAdd(1, healthOffsets, healthAddress);
				if (!healthStatus)
				{
					freezeHealthLB->Text = "OFF";
					if (addressToWrite)writeToMemory(addressToWrite, healthDefaultValue, 2);
				}
				else freezeHealthLB->Text = "ON";
			}

			/// ======== Rapid Fire
			if (GetAsyncKeyState(VK_F3)) {
				onePressTMR = clock();
				rFireStatus = !rFireStatus;
				if (rFireStatus) {
					rapidFireLB->Text = "ON";
					writeToMemory(rFireAddress, rFireOpc, 2);
				}
				else {
					rapidFireLB->Text = "OFF";
					writeToMemory(rFireAddress, rFireDefaultOpc, 2);
				}
			}

			/// ======== Recoil 
			if (GetAsyncKeyState(VK_F4)) {
				onePressTMR = clock();
				recoilStatus = !recoilStatus;
				if (recoilStatus) {
					recoilLB->Text = "ON";
					for (int i = 0; i < 7; i++) {
						writeToMemory(recoilAddress[i], stringToChar(Nops[noOfByte[i]-1]), noOfByte[i]);
					}
					
				}
				else {
					recoilLB->Text = "OFF";
					for (int i = 0; i < 7; i++) {
						writeToMemory(recoilAddress[i], stringToChar(recoilDefaultOpc[noOfByte[i] - 1]), noOfByte[i]);
					}
				}
			}

			//======== auto all gun
			if (GetAsyncKeyState(VK_F5)) {
				onePressTMR = clock();
				autoGunStatus = !autoGunStatus;
				if (autoGunStatus) {
					autoGunLb->Text = "ON";
					writeToMemory(autoGunAddress, autoGunOpc, 2);
				}
				else {
					autoGunLb->Text = "OFF";
					writeToMemory(autoGunAddress, autoGunDefaultOpc, 2);
				}
			}
		}
		if (healthStatus) {
			if (addressToWrite) {
				writeToMemory(addressToWrite, healtValue, 2);
			}
		}
	}

	char *stringToChar(std::string stringToConvert) {
		char *newChar = new char[stringToConvert.length()+1];
		strcpy(newChar, stringToConvert.c_str());
		return newChar;
	}

	void writeToMemory(DWORD address, char* valueToWrite, int byteNum) {
		unsigned long oldProtection;
		VirtualProtect((LPVOID)address, byteNum, PAGE_EXECUTE_READWRITE, &oldProtection);
		memcpy((LPVOID)address, valueToWrite, byteNum);
		VirtualProtect((LPVOID)address, byteNum, oldProtection, NULL);
	}

	
	DWORD FindAdd(int pointerLevel, DWORD offsets[], DWORD baseAddress) {
		DWORD ptr = *(DWORD*)(baseAddress);
		if (ptr == 0)return NULL;
		for (int i = 0; i < pointerLevel;i++) {
			if (i == pointerLevel - 1) {
				ptr = (DWORD)(ptr + offsets[i]);
				if (ptr == 0)return NULL;
				return ptr;
			}
			else {
				ptr = *(DWORD*)(ptr + offsets[i]);
				if (ptr == 0)return NULL;
			}
		}
		return ptr;
	}


	// ===========>>> Find offset from the module <<<=====================

	//DWORD GetModuleBaseAddress(DWORD dwProcID, const TCHAR *szModuleName)
	//{
	//	//uintptr_t
	//	DWORD ModuleBaseAddress = 0;
	//	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, dwProcID);
	//	if (hSnapshot != INVALID_HANDLE_VALUE)
	//	{
	//		MODULEENTRY32 ModuleEntry32;
	//		ModuleEntry32.dwSize = sizeof(MODULEENTRY32);
	//		if (Module32First(hSnapshot, &ModuleEntry32))
	//		{
	//			do
	//			{
	//				if (_tcsicmp(ModuleEntry32.szModule, szModuleName) == 0)
	//				{
	//					ModuleBaseAddress = (DWORD)ModuleEntry32.modBaseAddr;
	//					break;
	//				}
	//			} while (Module32Next(hSnapshot, &ModuleEntry32));
	//		}
	//		CloseHandle(hSnapshot);
	//	}
	//	return ModuleBaseAddress;
	//}
};
}
