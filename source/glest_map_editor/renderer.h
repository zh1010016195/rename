#ifndef RENDERER_H
#define RENDERER_H

#include <QGraphicsScene>
#include "map_preview.h"
#include <string>
#include <vector>

using namespace std;

using namespace Shared::Map;

class RenderTile;

class Renderer{
	public:
		Renderer();
		~Renderer();
		void reduceHeight(int height);
		void changeSurface(int surface);
		QGraphicsScene *getScene() const;
		RenderTile* at(int column, int row) const;
		void recalculateAll();
		void updateMap();
		int getHeight() const;
		int getWidth() const;
		void open(string path);
		MapPreview *getMap() const;
		void newMap();
	private:
		void removeTiles();
		void createTiles();
		QGraphicsScene *scene;
		RenderTile*** tiles;
		MapPreview *map;
		int height;
		int width;
		vector<MapPreview*> history;
		int historyPos;
		void addHistory();
		void redo();
		void undo();
};

#endif
