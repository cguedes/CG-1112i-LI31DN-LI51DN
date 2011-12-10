package cg.algorithms.circle;

import java.awt.Color;
import java.awt.Point;

import sun.reflect.generics.reflectiveObjects.NotImplementedException;

import cg.GUI.IRasterDevice;
import cg.algorithms.line.LineAlgorithmChooser;

public class CircleFillAlgorithm implements ICircleAlgorithm {

	public void fillCircle(IRasterDevice dc, Point center, int radius) {
		fillCircle(dc, center, radius, Color.BLACK);
	}
	public void fillCircle(IRasterDevice dc, Point center, int radius, Color color)
	{
		int x=0;
		int y=radius;
		int d=1-radius;
		
		writeCircleLine(dc,x,y,center,color);
		while( y > x)
		{
			if(d<0) //choose E
			{
				d+=2*x+3;
			}
			else
			{
				d+=2*(x-y)+5;
				--y;				
			}
			++x;
			writeCircleLine(dc,x,y,center,color);
		}
	}
	
	public void writeCircleLine(IRasterDevice dc,int x,int y, Point center, Color color)
	{
	
		
		while( y >= x)
		{
			dc.writePixel(+ x + center.x, + y + center.y, color);
			dc.writePixel(+ y + center.x, + x + center.y, color);
			dc.writePixel(+ y + center.x, - x + center.y, color);
			dc.writePixel(+ x + center.x, - y + center.y, color);
			dc.writePixel(- x + center.x, - y + center.y, color);
			dc.writePixel(- y + center.x, - x + center.y, color);
			dc.writePixel(- y + center.x, + x + center.y, color);
			dc.writePixel(- x + center.x, + y + center.y, color);
			--y;
		}
	}


	
	
	
	
	
	
	
	
	public void drawCircle(IRasterDevice dc, Point center, int radius) {
		drawCircle(dc, center, radius, Color.BLACK);
	}

	public void drawCircle(IRasterDevice dc, Point center, int radius,Color color) 
	{
		int x=0;
		int y=radius;
		int d=1-radius;
		
		writeCircle(dc,x,y,center,color);
		while( y > x)
		{
			if(d<0) //choose E
			{
				d+=2*x+3;
			}
			else
			{
				d+=2*(x-y)+5;
				--y;				
			}
			++x;
			writeCircle(dc,x,y,center,color);
		}
	}

	public void writeCircle(IRasterDevice dc,int x,int y, Point center, Color color)
	{
		dc.writePixel(+ x + center.x, + y + center.y, color);
		dc.writePixel(+ y + center.x, + x + center.y, color);
		dc.writePixel(+ y + center.x, - x + center.y, color);
		dc.writePixel(+ x + center.x, - y + center.y, color);
		dc.writePixel(- x + center.x, - y + center.y, color);
		dc.writePixel(- y + center.x, - x + center.y, color);
		dc.writePixel(- y + center.x, + x + center.y, color);
		dc.writePixel(- x + center.x, + y + center.y, color);
	}
}
