package cg.algorithms.line;

import java.awt.Color;
import java.awt.Point;

import cg.GUI.IRasterDevice;

public class BresenhamLineAlgorithm implements IScanLineAlgorithm 
{

	public void drawLine(IRasterDevice dc, Point start, Point end) 
	{
		drawLine(dc,start,end,Color.BLACK); 

	}
	
	public void drawLine(IRasterDevice dc, Point start, Point end, Color color) 
	{
		int dx=end.x-start.x,dy=end.y-start.y;
		 
		int e=0;
		int y=start.y;
		int x=start.x;			  
		 
		for( ; x < end.x; ++x)
		{	
			dc.writePixel(x,y,color); 
			e+=dy; 				
			if(2*e >= dx)
		    {
			    ++y;
			    e-=dx;	
			}
			
		}		
	}

}
