package cg.GUI;

import java.awt.Color;
import java.awt.Component;
import java.awt.Point;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

/**
 * @author  cguedes
 */
public interface IRasterDevice {
	
	// Integração com o java
	/**
	 */
	public Component getComponent();

	// Métodos de raster 2D
	public void writePixel(int x, int y, Color color);
	public void clear();
	
	// Debug
	public void addLine(Point p1, Point p2);
	public void addCircle(Point p1, int radius);
	public void setDebugMode(boolean isDebugOn);
	public boolean isInDebugMode();
	public void incGridSize();
	public void decGridSize();
	public void invalidateScreenData();
	public void drawStatusString(String str);
	
	public void drawInfoLines(Point p1[], int nPoints);
	public void drawInfoCircle(Point c, Point r);
	public void drawInfoRectgangle(Point a, Point b);
	public void clearInfo();
	
	// Geração de eventos
	public void addClickListener(MouseListener ml);
	public void addMotionListener(MouseMotionListener ml);
	
}