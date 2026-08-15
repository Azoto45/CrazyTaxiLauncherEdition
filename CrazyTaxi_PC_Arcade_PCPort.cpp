#define SDL_MAIN_HANDLED
#include <iostream>
#include <windows.h> 
#include <string>
#include <vector>
#include <SDL.h>

std::string OttieniCartellaEseguibile() {
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string percorsoStr(buffer);
    size_t ultimoSlash = percorsoStr.find_last_of("\\/");
    return percorsoStr.substr(0, ultimoSlash);
}

bool ControllaFileEsistente(const std::string& percorso) {
    DWORD attr = GetFileAttributesA(percorso.c_str());
    return (attr != INVALID_FILE_ATTRIBUTES && !(attr & FILE_ATTRIBUTE_DIRECTORY));
}

int main(int argc, char* argv[]) {
    SDL_SetMainReady();
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) < 0) return -1;

    std::cout << "--- Progetto Crazy Taxi Arcade PC Port v1.0 ---" << std::endl;
    std::cout << "[LAUNCHER] Configurazione memoria controlli universali..." << std::endl;

    std::string cartellaBase = OttieniCartellaEseguibile();
    std::string exeMotore = cartellaBase + "\\mame.exe";
    std::string percorsoRoms = cartellaBase + "\\roms";
    std::string percorsoCfg = cartellaBase + "\\cfg"; // NUOVO: Percorso della cartella dei comandi

    // Adattamento automatico se avviato dall'IDE di Visual Studio
    if (!ControllaFileEsistente(exeMotore)) {
        std::string percorsoSviluppo = cartellaBase + "\\x64\\Release";
        if (ControllaFileEsistente(percorsoSviluppo + "\\mame.exe")) {
            exeMotore = percorsoSviluppo + "\\mame.exe";
            percorsoRoms = percorsoSviluppo + "\\roms";
            percorsoCfg = percorsoSviluppo + "\\cfg";
        }
    }

    if (!ControllaFileEsistente(exeMotore)) {
        std::cerr << "[ERRORE CRITICO] Manca mame.exe!" << std::endl;
        SDL_Quit();
        return -1;
    }

    std::string nomeRom = "crzytaxi";

    // PARAMETRI DI LANCIO AGGIORNATI CON MEMORIZZAZIONE COMANDI:
    // -cfg_directory: dice a MAME di salvare e leggere i tasti impostati dentro la nostra cartella 'cfg'
    std::string comandoCompleto = "\"" + exeMotore + "\" -rompath \"" + percorsoRoms + "\" -cfg_directory \"" + percorsoCfg + "\" -bios none -nowindow -skip_gameinfo " + nomeRom;

    STARTUPINFOA si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    std::cout << "[LAUNCHER] Boot autonomo con caricamento configurazione tasti..." << std::endl;

    std::vector<char> comandoCaratteri(comandoCompleto.begin(), comandoCompleto.end());
    comandoCaratteri.push_back('\0');

    if (CreateProcessA(NULL, comandoCaratteri.data(), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        std::cout << "[SUCCESSO] Gioco avviato. I tuoi comandi sono al sicuro!" << std::endl;
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    else {
        std::cerr << "[ERRORE] Chiamata fallita." << std::endl;
    }

    SDL_Quit();
    return 0;
}
