#pragma once

#include "Components.h"
#include <algorithm>

struct configuration
{
	casing* pCase;
	powerSupply* pPowerSupply;
	videoCard* pVideoCard;
	storage* pStorage;
	memory* pMemory;
	cpuCooler* pCpuCooler;
	motherboard* pMotherBoard;
	cpu* pCpu;
};

class Application
{
private:
	enum pc_components
	{
		cNone = 0,
		cMotherboard,
		cProcessor,
		cMemory,
		cCooler,
		cStorage,
		cVideoCard,
		cPowerSupply,
		cCase,
		cTotal
	};

	pc_components m_SelectedCompenent;
	Renderer2D* m_Renderer;

	std::vector<casing> vCase;
	std::vector<powerSupply> vPowerSupply;
	std::vector<videoCard> vVideoCard;
	std::vector<storage> vStorage;
	std::vector<memory> vMemory;
	std::vector<cpuCooler> vCpuCooler;
	std::vector<motherboard> vMotherboard;
	std::vector<cpu> vCpu;

	configuration m_Configuration;

	i32 m_UsedMotherBoard;
	i32 m_UsedProcessor;
	i32 m_UsedMemory;
	i32 m_UsedCooler;
	i32 m_UsedStorage;
	i32 m_UsedVideoCard;
	i32 m_UsedPowerSupply;
	i32 m_UsedCase;

	f32 m_UserPrice;
	f32 m_LeftPrice;

	static const char* s_ComponentNames[pc_components::cTotal - 1];

	void SetComponents();

	void MotherBoardDataDisplay(motherboard& m);
	void MemoryDataDisplay(memory& m);
	void ProcessorDataDisplay(cpu& m);
	void VideoCardDataDisplay(videoCard& m);
	void PowerSupplyDataDisplay(powerSupply& m);
	void CaseDataDisplay(casing& m);
	void StorageDataDisplay(storage& m);
	void CPUCoolerDataDisplay(cpuCooler& m);

	void CurrentMenuSelection();
	void UserConfiguration();
public:
	void Init(Renderer2D* renderer);
	void Update();
	void ImGUIFrame();
	void Render();
};

const char* Application::s_ComponentNames[Application::pc_components::cTotal - 1] =
{
	"Motherboard", "Processor", "Memory", "Cooler", "Storage", "Video Card", "Power Supply", "Case"
};

void Application::MotherBoardDataDisplay(motherboard& m) {
	ImGui::BulletText("Socket: %s", m.socket.c_str());
	ImGui::BulletText("Form Factor: %s", m.formFactor.c_str());
	ImGui::BulletText("Ram Slot: %u", m.ramSlot);
	ImGui::BulletText("Max Ram Suported: %u", m.maxRam);
	ImGui::BulletText("Average Rate: %.2f", m.maxRam);
	ImGui::BulletText("Average Price: NPRs.%.2f", m.price * 114.72);
}

void Application::MemoryDataDisplay(memory& m)
{
	ImGui::BulletText("Speed: %s", m.speed.c_str());
	ImGui::BulletText("Type: %s", m.type.c_str());
	ImGui::BulletText("CAS: %i", m.cas);
	ImGui::BulletText("Mod X Each Mod: %u X %u", m.numModule, m.eachModule);
	ImGui::BulletText("Size: %u", m.size);
	ImGui::BulletText("Average Rating: %.2f", m.avgRating);
	ImGui::BulletText("Average Price: NPRs.%.2f", m.price * 114.72);
}

inline void Application::ProcessorDataDisplay(cpu & m)
{
	ImGui::BulletText("Speed: %.2f", m.speed);
	ImGui::BulletText("Cores: %u", m.core);
	ImGui::BulletText("Power: %u", m.power);
	ImGui::BulletText("Average Rate: %.2f", m.avgRate);
	ImGui::BulletText("Average Price: NPRs.%.2f", m.price * 114.72);
}

inline void Application::VideoCardDataDisplay(videoCard & m)
{
	ImGui::BulletText("Series: %s", m.series.c_str());
	ImGui::BulletText("Chipset: %s", m.chipset.c_str());
	ImGui::BulletText("Memory: %u GB", m.memory);
	ImGui::BulletText("Clk Rate: %.2f GHz", m.ClkCore);
	ImGui::BulletText("Average Rate: %.2f", m.avgRate);
	ImGui::BulletText("Average Price: NPRs.%.2f", m.price * 114.72);
}

inline void Application::PowerSupplyDataDisplay(powerSupply & m)
{
	ImGui::BulletText("Series: %s", m.series.c_str());
	ImGui::BulletText("Form: %s", m.form.c_str());
	ImGui::BulletText("Efficiency: %s", m.efficiency.c_str());
	ImGui::BulletText("Power: %i W", m.power);
	ImGui::BulletText("Modular: %s", m.modular.c_str());
	ImGui::BulletText("Average Rating: %.2f", m.avgRate);
	ImGui::BulletText("Average Price: NPRs.%.2f", m.price * 114.72);
}

inline void Application::CaseDataDisplay(casing & m)
{
	ImGui::BulletText("Type: %s", m.type.c_str());
	ImGui::BulletText("Average Price: NPRs.%.2f", m.price * 114.72);
}

inline void Application::StorageDataDisplay(storage & m)
{
	ImGui::BulletText("Series: %s", m.series.c_str());
	ImGui::BulletText("Form: %s", m.form.c_str());
	ImGui::BulletText("Type: %s", m.type.c_str());
	ImGui::BulletText("Capacity: %s", m.capacity.c_str());
	ImGui::BulletText("Cache: %.2f MB", m.cache);
	ImGui::BulletText("Average Rating: %.2f", m.avgRate);
	ImGui::BulletText("Average Price: NPRs.%.2f", m.price * 114.72);
}

inline void Application::CPUCoolerDataDisplay(cpuCooler & m)
{
	ImGui::BulletText("Min RPM: %u", m.minRpm);
	ImGui::BulletText("Max RPM: %u", m.maxRpm);
	ImGui::BulletText("Noise Level: %u", m.noiseLevel);
	ImGui::BulletText("Average Rating: %.2f", m.avgRate);
	ImGui::BulletText("Average Price: NPRs.%.2f", m.price * 114.72);
}

void Application::SetComponents()
{
	vCase.push_back(casing{ "Thermaltake Core G3","ATX Mid Tower",69.49f });
	vCase.push_back(casing{ "Lian-Li PC-O10 WX","ATX Mid Tower",249.99f });

	vPowerSupply.push_back(powerSupply{ "EVGA SuperNOVA 750","SuperNOVA G3","ATX","80+ Gold",750,"Full",4.5f,99.89f });
	vPowerSupply.push_back(powerSupply{ "Corsair CX550M","CXM","ATX","80+ Bronze",550,"Semi",4.5f,33.99f });
	vPowerSupply.push_back(powerSupply{ "Corsair TX650M Gold","TXM Gold","ATX","80+ Gold",650,"Semi",4.5f,39.89f });

	vVideoCard.push_back(videoCard{ "MSI GeForce GTX 1060 6GT OCV1","GT OCV1","GeForce GTX 1060 6GB",6,1.544f,4.5f, 529.89f });
	vVideoCard.push_back(videoCard{ "Asus DUAL-GTX1070-O8G","Dual Series","GeForce GTX 1070",8,1.582f,4.5f, 439.89f });
	vVideoCard.push_back(videoCard{ "Gigabyte GV-RX570AORUS-4GD","AORUS 4G","Radeon RX 570",4,1.168f,4.0f, 139.99f });

	vStorage.push_back(storage{ "Western Digital WD10EZEX","Caviar Blue","3.5","7200 RPM","1 TB",64,4.5f,44.89f });
	vStorage.push_back(storage{ "Samsung MZ-76E500B/AM","860 Evo","2.5","SSD","500 GB",512,4,82.99f });
	vStorage.push_back(storage{ "Intel SSDPECME040T401","DC P3608","PCI-E","SSD","4 TB",0,0,8867.99f });

	vMemory.push_back(memory{ "Corsair Vengeance LPX","DDR4-3000","288-pin DIMM",15,2,8,16,4.5f,114.99f });
	vMemory.push_back(memory{ "G.Skill Aegis","DDR4-3000","288-pin DIMM",15,2,8,16,4.5f,94.99f });
	vMemory.push_back(memory{ "Team Vulcan","DDR4-3000","288-pin DIMM",15,2,4,8,4.5f,60.88f });

	vCpuCooler.push_back(cpuCooler{ "Cooler Master Hyper 212 EVO",600,2000,36,4.5f,27.89f });
	vCpuCooler.push_back(cpuCooler{ "Cooler Master Hyper T2",0,2800,35,4,16.89f });
	vCpuCooler.push_back(cpuCooler{ "be quiet! Dark Rock 4",0,1400,35,4.5f,68.99f });

	vCpu.push_back(cpu{ "Intel Core i7 - 8700K",3.7f,6,95,4.5f,369.99f });
	vCpu.push_back(cpu{ "Intel Core i9 - 9900K",3.6f,8,95,4.5f,529.99f });
	vCpu.push_back(cpu{ "Intel Core i5 - 9600K",3.7f,6,95,4.5f,259.99f });

	vMotherboard.push_back(motherboard{ "MSI Z370-A PRO","LGA1151","ATX",4,64,4,109.89f });
	vMotherboard.push_back(motherboard{ "Asus PRIME Z390-A","LGA1151","ATX",4,64,0,183.00f });
	vMotherboard.push_back(motherboard{ "Gigabyte H310M A","LGA1151","Micro ATX",2,32,5,55.99f });

	m_Configuration.pCase = 0;
	m_Configuration.pCpu = 0;
	m_Configuration.pCpuCooler = 0;
	m_Configuration.pMemory = 0;
	m_Configuration.pMotherBoard = 0;
	m_Configuration.pPowerSupply = 0;
	m_Configuration.pStorage = 0;
	m_Configuration.pVideoCard = 0;

#define PRESENT_COMPONENT(x) ((x)!=-1)
	m_UsedMotherBoard = -1;
	m_UsedProcessor = -1;
	m_UsedMemory = -1;
	m_UsedCooler = -1;
	m_UsedStorage = -1;
	m_UsedVideoCard = -1;
	m_UsedPowerSupply = -1;
	m_UsedCase = -1;

#define SORT_ORDER() [](auto& a, auto& b) { return a.price < b.price; }
	std::sort(vMotherboard.begin(), vMotherboard.end(), SORT_ORDER());
	std::sort(vCpu.begin(), vCpu.end(), SORT_ORDER());
	std::sort(vMemory.begin(), vMemory.end(), SORT_ORDER());
	std::sort(vCpuCooler.begin(), vCpuCooler.end(), SORT_ORDER());
	std::sort(vStorage.begin(), vStorage.end(), SORT_ORDER());
	std::sort(vVideoCard.begin(), vVideoCard.end(), SORT_ORDER());
	std::sort(vPowerSupply.begin(), vPowerSupply.end(), SORT_ORDER());
	std::sort(vCase.begin(), vCase.end(), SORT_ORDER());
}

#define DISPLAY_CBUTTON(m) \
if (ImGui::Button(m.name.c_str(), ImVec2(250.0f, 30.0f))) \
{ \
	if (currentOpen == i) \
		currentOpen = 0; \
	else \
		currentOpen = i; \
}

inline void Application::CurrentMenuSelection()
{
	static i32 currentOpen = -1;
	ImGui::Begin(s_ComponentNames[m_SelectedCompenent - 1]);
	switch (m_SelectedCompenent)
	{
	case cMotherboard:
	{
		for (int i=0; i<vMotherboard.size(); ++i)
		{
			auto& m = vMotherboard[i];
			if (m_LeftPrice < m.price * 114.72f) continue;
			DISPLAY_CBUTTON(m);
			if (currentOpen == i)
			{
				MotherBoardDataDisplay(m);
				bool used = (m_UsedMotherBoard==i);
				ImGui::Checkbox("Use", &used);
				if (used) m_UsedMotherBoard = i; else {
					if(m_UsedMotherBoard == i)
						m_UsedMotherBoard = -1;
				}
			}
		}
	} break;

	case cProcessor:
	{
		for (int i = 0; i < (i32)vCpu.size(); ++i)
		{
			auto& m = vCpu[i];
			if (m_LeftPrice < m.price * 114.72f) continue;
			DISPLAY_CBUTTON(m);
			if (currentOpen == i)
			{
				ProcessorDataDisplay(m);
				bool used = (m_UsedProcessor == i);
				ImGui::Checkbox("Use", &used);
				if (used) m_UsedProcessor = i; else {
					if (m_UsedProcessor == i)
						m_UsedProcessor = -1;
				}
			}
		}
	} break;

	case cMemory:
	{
		for (int i = 0; i < vMemory.size(); ++i)
		{
			auto& m = vMemory[i];
			if (m_LeftPrice < m.price * 114.72f) continue;
			DISPLAY_CBUTTON(m);
			if (currentOpen == i)
			{
				MemoryDataDisplay(m);
				bool used = (m_UsedMemory == i);
				ImGui::Checkbox("Use", &used);
				if (used) m_UsedMemory = i;  else {
					if (m_UsedMemory == i)
						m_UsedMemory = -1;
				}
			}
		}
	} break;

	case cCooler:
	{
		for (int i = 0; i < vCpuCooler.size(); ++i)
		{
			auto& m = vCpuCooler[i];
			if (m_LeftPrice < m.price * 114.72f) continue;
			DISPLAY_CBUTTON(m);
			if (currentOpen == i)
			{
				CPUCoolerDataDisplay(m);
				bool used = (m_UsedCooler == i);
				ImGui::Checkbox("Use", &used);
				if (used) m_UsedCooler = i;  else {
					if (m_UsedCooler == i)
						m_UsedCooler = -1;
				}
			}
		}
	} break;

	case cStorage:
	{
		for (int i = 0; i < vStorage.size(); ++i)
		{
			auto& m = vStorage[i];
			if (m_LeftPrice < m.price * 114.72f) continue;
			DISPLAY_CBUTTON(m);
			if (currentOpen == i)
			{
				StorageDataDisplay(m);
				bool used = (m_UsedStorage == i);
				ImGui::Checkbox("Use", &used);
				if (used) m_UsedStorage = i;  else {
					if (m_UsedStorage == i)
						m_UsedStorage = -1;
				}
			}
		}
	} break;

	case cVideoCard:
	{
		for (int i = 0; i < vVideoCard.size(); ++i)
		{
			auto& m = vVideoCard[i];
			if (m_LeftPrice < m.price * 114.72f) continue;
			DISPLAY_CBUTTON(m);
			if (currentOpen == i)
			{
				VideoCardDataDisplay(m);
				bool used = (m_UsedVideoCard == i);
				ImGui::Checkbox("Use", &used);
				if (used) m_UsedVideoCard = i; else {
					if (m_UsedVideoCard == i)
						m_UsedVideoCard = -1;
				}
			}
		}
	} break;

	case cPowerSupply:
	{
		for (int i = 0; i < vPowerSupply.size(); ++i)
		{
			auto& m = vPowerSupply[i];
			if (m_LeftPrice < m.price * 114.72f) continue;
			DISPLAY_CBUTTON(m);
			if (currentOpen == i)
			{
				PowerSupplyDataDisplay(m);
				bool used = (m_UsedPowerSupply == i);
				ImGui::Checkbox("Use", &used);
				if (used) m_UsedPowerSupply = i; else {
					if (m_UsedPowerSupply == i)
						m_UsedPowerSupply = -1;
				}
			}
		}
	} break;

	case cCase:
	{
		for (int i = 0; i < vCase.size(); ++i)
		{
			auto& m = vCase[i];
			if (m_LeftPrice < m.price * 114.72f) continue;
			DISPLAY_CBUTTON(m);
			if (currentOpen == i)
			{
				CaseDataDisplay(m);
				bool used = (m_UsedCase == i);
				ImGui::Checkbox("Use", &used);
				if (used) m_UsedCase = i; else {
					if (m_UsedCase == i)
						m_UsedCase = -1;
				}
			}
		}
	} break;
	}
	ImGui::End();

	if (PRESENT_COMPONENT(m_UsedMotherBoard))
		m_Configuration.pMotherBoard = &vMotherboard[m_UsedMotherBoard];
	else
		m_Configuration.pMotherBoard = 0;
	
	if (PRESENT_COMPONENT(m_UsedProcessor))
		m_Configuration.pCpu = &vCpu[m_UsedProcessor];
	else
		m_Configuration.pCpu = 0;

	if (PRESENT_COMPONENT(m_UsedMemory))
		m_Configuration.pMemory = &vMemory[m_UsedMemory];
	else
		m_Configuration.pMemory = 0;

	if (PRESENT_COMPONENT(m_UsedCooler))
		m_Configuration.pCpuCooler = &vCpuCooler[m_UsedCooler];
	else
		m_Configuration.pCpuCooler= 0;

	if (PRESENT_COMPONENT(m_UsedStorage))
		m_Configuration.pStorage = &vStorage[m_UsedStorage];
	else
		m_Configuration.pStorage = 0;

	if (PRESENT_COMPONENT(m_UsedVideoCard))
		m_Configuration.pVideoCard = &vVideoCard[m_UsedVideoCard];
	else
		m_Configuration.pVideoCard = 0;

	if (PRESENT_COMPONENT(m_UsedPowerSupply))
		m_Configuration.pPowerSupply = &vPowerSupply[m_UsedPowerSupply];
	else
		m_Configuration.pPowerSupply = 0;

	if (PRESENT_COMPONENT(m_UsedCase))
		m_Configuration.pCase = &vCase[m_UsedCase];
	else
		m_Configuration.pCase = 0;
}

void Application::UserConfiguration()
{
	static i32 currentOpen = 0;

	ImGui::Begin("Selected Components");

	ImGui::Text("Say your price: ");
	ImGui::SameLine();
	ImGui::InputFloat(" ", &m_UserPrice);

	int numOfComponents = 0;
	f32 totalPrice = 0.0f;
	ImVec4 color(1.0f, 0.0f, 0.0f, 1.0f);

	if (m_Configuration.pMotherBoard)
	{
		numOfComponents++;
		auto i = Application::cMotherboard;
		auto& m = *m_Configuration.pMotherBoard;
		ImGui::TextColored(color, "%-20s", "Motherboard");
		ImGui::SameLine();
		DISPLAY_CBUTTON(m);
		if (currentOpen == i)
			MotherBoardDataDisplay(m);
		totalPrice += m.price;
	}
	
	if (m_Configuration.pCpu)
	{
		numOfComponents++;
		auto i = Application::cProcessor;
		auto& m = *m_Configuration.pCpu;
		ImGui::TextColored(color, "%-20s", "Processor");
		ImGui::SameLine();
		DISPLAY_CBUTTON(m);
		if (currentOpen == i)
			ProcessorDataDisplay(m);
		totalPrice += m.price;
	}

	if (m_Configuration.pMemory)
	{
		numOfComponents++;
		auto i = Application::cMemory;
		auto& m = *m_Configuration.pMemory;
		ImGui::TextColored(color, "%-20s", "Memory");
		ImGui::SameLine();
		DISPLAY_CBUTTON(m);
		if (currentOpen == i)
			MemoryDataDisplay(m);
		totalPrice += m.price;
	}

	if (m_Configuration.pCpuCooler)
	{
		numOfComponents++;
		auto i = Application::cCooler;
		auto& m = *m_Configuration.pCpuCooler;
		ImGui::TextColored(color, "%-20s", "CPU Cooler");
		ImGui::SameLine();
		DISPLAY_CBUTTON(m);
		if (currentOpen == i)
			CPUCoolerDataDisplay(m);
		totalPrice += m.price;
	}

	if (m_Configuration.pStorage)
	{
		numOfComponents++;
		auto i = Application::cStorage;
		auto& m = *m_Configuration.pStorage;
		ImGui::TextColored(color, "%-20s", "Storage");
		ImGui::SameLine();
		DISPLAY_CBUTTON(m);
		if (currentOpen == i)
			StorageDataDisplay(m);
		totalPrice += m.price;
	}

	if (m_Configuration.pVideoCard)
	{
		numOfComponents++;
		auto i = Application::cVideoCard;
		auto& m = *m_Configuration.pVideoCard;
		ImGui::TextColored(color, "%-20s", "Video Card");
		ImGui::SameLine();
		DISPLAY_CBUTTON(m);
		if (currentOpen == i)
			VideoCardDataDisplay(m);
		totalPrice += m.price;
	}

	if (m_Configuration.pPowerSupply)
	{
		numOfComponents++;
		auto i = Application::cPowerSupply;
		auto& m = *m_Configuration.pPowerSupply;
		ImGui::TextColored(color, "%-20s", "Power Supply");
		ImGui::SameLine();
		DISPLAY_CBUTTON(m);
		if (currentOpen == i)
			PowerSupplyDataDisplay(m);
		totalPrice += m.price;
	}

	if (m_Configuration.pCase)
	{
		numOfComponents++;
		auto i = Application::cCase;
		auto& m = *m_Configuration.pCase;
		ImGui::TextColored(color, "%-20s", "Case");
		ImGui::SameLine();
		DISPLAY_CBUTTON(m);
		if (currentOpen == i)
			CaseDataDisplay(m);
		totalPrice += m.price;
	}

	m_LeftPrice = m_UserPrice - totalPrice * 144.720f;
	if (m_UserPrice == 0.0f) m_LeftPrice = INFINITY;
	if (m_LeftPrice < 0.0f) m_LeftPrice = 0.0f;

	ImGui::TextColored(color, "Total number of compenents: %d", numOfComponents);
	ImGui::TextColored(color, "Total Price: %.2f", totalPrice * 114.720f);
	ImGui::TextColored(color, "Left Price: %.2f", m_LeftPrice);
	ImGui::End();
}

void Application::Init(Renderer2D* renderer)
{
	// Load textures
	ResourceManager::LoadTexture("res/Case.png", GL_TRUE, "case");
	ResourceManager::LoadTexture("res/Cooler.png", GL_TRUE, "cooler");
	ResourceManager::LoadTexture("res/Memory.png", GL_TRUE, "memory");
	ResourceManager::LoadTexture("res/MotherBoard.png", GL_TRUE, "motherboard");
	ResourceManager::LoadTexture("res/PowerSupply.png", GL_TRUE, "powersupply");
	ResourceManager::LoadTexture("res/Processor.png", GL_TRUE, "processor");
	ResourceManager::LoadTexture("res/Storage.png", GL_TRUE, "storage");
	ResourceManager::LoadTexture("res/VideoCard.png", GL_TRUE, "videocard");
	// Set render-specific controls
	m_Renderer = renderer;

	m_UserPrice = 0.0f;
	m_LeftPrice = 0.0f;

	m_SelectedCompenent = cMotherboard;
	SetComponents();
}

void Application::Update()
{

}

void Application::ImGUIFrame()
{
	static float f = 0.0f;
	static int counter = 0;

	ImGui::Begin("PC Components:");
	ImVec2 size;
	size.x = 300.0f;
	size.y = 40.0f;
	if (ImGui::Button("Motherboards", size)) m_SelectedCompenent = cMotherboard;
	if (ImGui::Button("Processor", size)) m_SelectedCompenent = cProcessor;
	if (ImGui::Button("Memory", size)) m_SelectedCompenent = cMemory;
	if (ImGui::Button("Storage", size)) m_SelectedCompenent = cStorage;
	if (ImGui::Button("Case", size)) m_SelectedCompenent = cCase;
	if (ImGui::Button("Cooler", size)) m_SelectedCompenent = cCooler;
	if (ImGui::Button("Power Supply", size)) m_SelectedCompenent = cPowerSupply;
	if (ImGui::Button("Video Card", size)) m_SelectedCompenent = cVideoCard;
	ImGui::End();
	CurrentMenuSelection();
	UserConfiguration();
}

void Application::Render()
{
	if (m_Configuration.pMotherBoard)
	{
		auto& tex = ResourceManager::GetTexture("motherboard");
		v2 dimension;
		dimension.x = 400.0f;
		dimension.y = 400.0f;
		m_Renderer->Draw(tex, v2{ 150.0f, 150.0f }, dimension);
	}

	if (m_Configuration.pCpu)
	{
		auto& tex = ResourceManager::GetTexture("processor");
		v2 dimension;
		dimension.x = 100.0f;
		dimension.y = 100.0f;
		m_Renderer->Draw(tex, v2{ 580.0f, 300.0f }, dimension);
	}

	if (m_Configuration.pMemory)
	{
		auto& tex = ResourceManager::GetTexture("memory");
		v2 dimension;
		dimension.x = 130.0f;
		dimension.y = 130.0f;
		m_Renderer->Draw(tex, v2{ 500.0f, 550.0f }, dimension);
	}

	if (m_Configuration.pCpuCooler)
	{
		
	}

	if (m_Configuration.pStorage)
	{

	}

	if (m_Configuration.pVideoCard)
	{

	}

	if (m_Configuration.pPowerSupply)
	{

	}

	if (m_Configuration.pCase)
	{

	}

}

