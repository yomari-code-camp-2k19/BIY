#pragma once

#include "Components.h"

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

	static const char* s_ComponentNames[pc_components::cTotal - 1];

	void SetComponents();

	void MotherBoardDataDisplay(motherboard& m);
	void ProcessorDataDisplay(cpu& m);
	void VideoCardDataDisplay(videoCard& m);
	void PowerSupplyDataDisplay(powerSupply& m);
	void CaseDataDisplay(casing& m);
	void MemoryDataDisplay(memory& m);
	void StorageDataDisplay(storage& m);
	void CurrentMenuSelection();
	void UserConfiguration();
public:
	void Init();
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
	ImGui::BulletText("Average Price: NPRs.%.2f", m.Price * 114.72);
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
}

#define DISPLAY_CBUTTON(m) \
if (ImGui::Button(m.name.c_str(), ImVec2(200.0f, 30.0f))) \
{ \
	if (currentOpen == i) \
		currentOpen = -1; \
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
			DISPLAY_CBUTTON(m);
			if (currentOpen == i)
			{
				MotherBoardDataDisplay(m);
				/*ImGui::BulletText("Socket: %s", m.socket.c_str());
				ImGui::BulletText("Form Factor: %s", m.formFactor.c_str());
				ImGui::BulletText("Ram Slot: %u", m.ramSlot);
				ImGui::BulletText("Max Ram Suported: %u", m.maxRam);
				ImGui::BulletText("Average Rate: %.2f", m.maxRam);
				ImGui::BulletText("Average Price: NPRs.%.2f", m.price * 114.72);*/
				bool used = (m_UsedMotherBoard==i);
				ImGui::Checkbox("Use", &used);
				if (used) m_UsedMotherBoard = i;
			}
		}
	} break;

	case cProcessor:
	{
		for (int i = 0; i < (i32)vCpu.size(); ++i)
		{
			auto& m = vCpu[i];
			DISPLAY_CBUTTON(m);
			if (currentOpen == i)
			{
				ImGui::BulletText("Speed: %.2f", m.speed);
				ImGui::BulletText("Cores: %u", m.core);
				ImGui::BulletText("Power: %u", m.power);
				ImGui::BulletText("Average Rate: %.2f", m.avgRate);
				ImGui::BulletText("Average Price: NPRs.%.2f", m.price * 114.72);
				bool used = (m_UsedProcessor == i);
				ImGui::Checkbox("Use", &used);
				if (used) m_UsedProcessor = i;
			}
		}
	} break;

	case cMemory:
	{
		for (int i = 0; i < vMemory.size(); ++i)
		{
			auto& m = vMemory[i];
			DISPLAY_CBUTTON(m);
			if (currentOpen == i)
			{
				MemoryDataDisplay(m);
				/*ImGui::BulletText("Speed: %s", m.speed.c_str());
				ImGui::BulletText("Type: %s", m.type.c_str());
				ImGui::BulletText("CAS: %i", m.cas);
				ImGui::BulletText("Mod X Each Mod: %u X %u", m.numModule, m.eachModule);
				ImGui::BulletText("Size: %u", m.size);
				ImGui::BulletText("Average Rating: %.2f", m.avgRating);
				ImGui::BulletText("Average Price: NPRs.%.2f", m.Price * 114.72);*/
				bool used = (m_UsedMemory == i);
				ImGui::Checkbox("Use", &used);
				if (used) m_UsedMemory = i;
			}
		}
	} break;

	case cCooler:
	{
		for (int i = 0; i < vCpuCooler.size(); ++i)
		{
			auto& m = vCpuCooler[i];
			DISPLAY_CBUTTON(m);
			if (currentOpen == i)
			{
				ImGui::BulletText("Min RPM: %u", m.minRpm);
				ImGui::BulletText("Max RPM: %u", m.maxRpm);
				ImGui::BulletText("Noise Level: %u", m.noiseLevel);
				ImGui::BulletText("Average Rating: %.2f", m.avgRate);
				ImGui::BulletText("Average Price: NPRs.%.2f", m.price * 114.72);
				bool used = (m_UsedCooler == i);
				ImGui::Checkbox("Use", &used);
				if (used) m_UsedCooler = i;
			}
		}
	} break;

	case cStorage:
	{
		for (int i = 0; i < vStorage.size(); ++i)
		{
			auto& m = vStorage[i];
			DISPLAY_CBUTTON(m);
			if (currentOpen == i)
			{
				ImGui::BulletText("Series: %s", m.series.c_str());
				ImGui::BulletText("Form: %s", m.form.c_str());
				ImGui::BulletText("Type: %s", m.type.c_str());
				ImGui::BulletText("Capacity: %s", m.capacity.c_str());
				ImGui::BulletText("Cache: %.2f MB", m.cache);
				ImGui::BulletText("Average Rating: %.2f", m.avgRate);
				ImGui::BulletText("Average Price: NPRs.%.2f", m.price * 114.72);
				bool used = (m_UsedStorage == i);
				ImGui::Checkbox("Use", &used);
				if (used) m_UsedStorage = i;
			}
		}
	} break;

	case cVideoCard:
	{
		for (int i = 0; i < vVideoCard.size(); ++i)
		{
			auto& m = vVideoCard[i];
			DISPLAY_CBUTTON(m);
			if (currentOpen == i)
			{
				ImGui::BulletText("Series: %s", m.series.c_str());
				ImGui::BulletText("Chipset: %s", m.chipset.c_str());
				ImGui::BulletText("Memory: %u GB", m.memory);
				ImGui::BulletText("Clk Rate: %.2f GHz", m.ClkCore);
				ImGui::BulletText("Average Rate: %.2f", m.avgRate);
				ImGui::BulletText("Average Price: NPRs.%.2f", m.Price * 114.72);
				bool used = (m_UsedVideoCard == i);
				ImGui::Checkbox("Use", &used);
				if (used) m_UsedVideoCard = i;
			}
		}
	} break;

	case cPowerSupply:
	{
		for (int i = 0; i < vPowerSupply.size(); ++i)
		{
			auto& m = vPowerSupply[i];
			DISPLAY_CBUTTON(m);
			if (currentOpen == i)
			{
				ImGui::BulletText("Series: %s", m.series.c_str());
				ImGui::BulletText("Form: %s", m.form.c_str());
				ImGui::BulletText("Efficiency: %s", m.efficiency.c_str());
				ImGui::BulletText("Power: %i W", m.power);
				ImGui::BulletText("Modular: %s", m.modular.c_str());
				ImGui::BulletText("Average Rating: %.2f", m.avgRate);
				ImGui::BulletText("Average Price: NPRs.%.2f", m.price * 114.72);
				bool used = (m_UsedPowerSupply == i);
				ImGui::Checkbox("Use", &used);
				if (used) m_UsedPowerSupply = i;
			}
		}
	} break;

	case cCase:
	{
		for (int i = 0; i < vCase.size(); ++i)
		{
			auto& m = vCase[i];
			DISPLAY_CBUTTON(m);
			if (currentOpen == i)
			{
				ImGui::BulletText("Type: %s", m.type.c_str());
				ImGui::BulletText("Average Price: NPRs.%.2f", m.price * 114.72);
				bool used = (m_UsedCase == i);
				ImGui::Checkbox("Use", &used);
				if (used) m_UsedCase = i;
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
	static i32 currentOpen = -1;
	ImGui::Begin("Selected Components");
	int numOfComponents = 0;

	if (m_Configuration.pMotherBoard)
	{
		numOfComponents++;

		//MotherBoardDataDisplay(*m_Configuration.pMotherBoard);
	}
	
	if (m_Configuration.pCpu)
	{
		numOfComponents++;
		//CPUDataDisplay(*m_Configuration.pCpu);
	}

	if (m_Configuration.pMemory)
	{
		numOfComponents++;
		//MemoryDataDisplay(*m_Configuration.pMemory);
	}

	if (m_Configuration.pCpuCooler)
	{
		numOfComponents++;
		//CPUCoolerDataDisplay(*m_Configuration.pCpuCooler);
	}

	if (m_Configuration.pStorage)
	{
		numOfComponents++;
		//StorageDataDisplay(*m_Configuration.pStorage);
	}

	if (m_Configuration.pVideoCard)
	{
		numOfComponents++;
		//VideoCardDataDisplay(*m_Configuration.pVideoCard);
	}

	if (m_Configuration.pPowerSupply)
	{
		numOfComponents++;
		//PowerSupplyDataDisplay(*m_Configuration.pPowerSupply);
	}

	if (m_Configuration.pCase)
	{
		numOfComponents++;
		//CaseDataDisplay(*m_Configuration.pCase);
	}

	ImGui::Text("Total number of compenents: %d", numOfComponents);
	ImGui::End();
}

void Application::Init()
{
	// Load shaders
	ResourceManager::LoadShader("shaders/vshader.vert", "shaders/fshader.frag", nullptr, "sprite");
	// Configure shaders
	m4x4 projection = m4x4::OrthographicC(0.0f, 1280.0f, 720.0f, 0.0f, -1.0f, 1.0f);
	ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
	ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
	// Load textures
	ResourceManager::LoadTexture("res/BigSmile.png", GL_TRUE, "smile");
	ResourceManager::LoadTexture("res/Case.png", GL_TRUE, "case");
	ResourceManager::LoadTexture("res/Cooler.png", GL_TRUE, "cooler");
	ResourceManager::LoadTexture("res/Memory.png", GL_TRUE, "memory");
	ResourceManager::LoadTexture("res/MotherBoard.png", GL_TRUE, "motherboard");
	ResourceManager::LoadTexture("res/PowerSupply.png", GL_TRUE, "powersupply");
	ResourceManager::LoadTexture("res/Processor.png", GL_TRUE, "processor");
	ResourceManager::LoadTexture("res/Storage.png", GL_TRUE, "storage");
	ResourceManager::LoadTexture("res/VideoCard.png", GL_TRUE, "videocard");
	// Set render-specific controls
	m_Renderer = new Renderer2D(ResourceManager::GetShader("sprite"));

	m_SelectedCompenent = cNone;
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
	if (m_SelectedCompenent)
		CurrentMenuSelection();
	UserConfiguration();
}

void Application::Render()
{
	m_Renderer->DrawSprite(ResourceManager::GetTexture("smile"), v2{ 200, 200 }, v2{ 300, 400 }, 45.0f, v3{ 0.0f, 1.0f, 0.0f });
}

