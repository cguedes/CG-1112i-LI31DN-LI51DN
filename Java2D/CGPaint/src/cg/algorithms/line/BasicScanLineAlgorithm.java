/**
 * 
 */
package cg.algorithms.line;

import java.awt.Color;
import java.awt.Point;

import cg.GUI.IRasterDevice;

/**
 * @author cguedes
 *
 */
public class BasicScanLineAlgorithm implements IScanLineAlgorithm {

	
	
	/* (non-Javadoc)
	 * @see cg.GUI.algorithms.IScanLineAlgorithm#drawLine(java.awt.Point, java.awt.Point)
	 */
	public void drawLine(IRasterDevice dc, Point start, Point end) {
		drawLine(dc, start, end, Color.BLACK);
	}

	/* (non-Javadoc)
	 * @see cg.GUI.algorithms.IScanLineAlgorithm#drawLine(java.awt.Point, java.awt.Point, java.awt.Color)
	 */
	public void drawLine(IRasterDevice dc, Point start, Point end, Color color) {
		double dy = end.y - start.y;
		double dx = end.x - start.x;
		double m = dy / dx;
	
		if(Math.abs(m)>=1.0)
		{
			if(end.y < start.y)
			{
				Point p=start;
				start=end;
				end=p;
			}
			double x = start.x;
			for (int y = start.y; y <= end.y; y++) 
			{
				dc.writePixel((int)Math.round(x), y, color);
				x += 1/m;
			}
		}
		else
		{
			if(end.x < start.x)
			{
				Point p=start;
				start=end;
				end=p;
			}
			double y = start.y;
			for (int x = start.x; x <= end.x; x++) {
				dc.writePixel(x, (int)Math.round(y), color);
				y += m;
			}
		}
	}

}
