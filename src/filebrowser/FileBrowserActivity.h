#pragma once

#include <vector>
#include <string>
#include "interface/Window.h"
#include "tasks/TaskListener.h"


class SaveFile;
class FileSelectedCallback
{
public:
	FileSelectedCallback() {}
	virtual  ~FileSelectedCallback() {}
	virtual void FileSelected(SaveFile* file) {}
};

namespace ui
{
	class ScrollPanel;
	class ProgressBar;
}

class LoadFilesTask;
class FileBrowserActivity: public ui::Window, public TaskListener
{
	LoadFilesTask * loadFiles;
	FileSelectedCallback * callback;
	ui::ScrollPanel * itemList;
	std::vector<SaveFile*> files;
	std::vector<ui::Component*> components;
	std::vector<ui::Component*> componentsQueue;
	std::string directory;

	ui::ProgressBar * progressBar;

	int totalFiles;
	int filesX, filesY, buttonPadding;
	int fileX, fileY;
	int buttonWidth, buttonHeight, buttonAreaWidth, buttonAreaHeight, buttonXOffset, buttonYOffset;

	void populateList();
public:
	FileBrowserActivity(std::string directory, FileSelectedCallback * callback);
	virtual void OnDraw();
	virtual void OnTick(float dt);
	virtual void OnMouseDown(int x, int y, unsigned button);
	void loadDirectory(std::string directory);
	void SelectSave(SaveFile * file);
	virtual ~FileBrowserActivity();

	virtual void NotifyDone(Task * task);
	virtual void NotifyError(Task * task);
	virtual void NotifyProgress(Task * task);
	virtual void NotifyStatus(Task * task);

	void Exit();
};