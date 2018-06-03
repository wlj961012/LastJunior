package com.bean;

import java.util.Date;

public class Storeinfo {
	private String sno;
	private String pno;
	private String kno;
	private int prprize;
	private int pnum;
	private Date pdate;
	public String getSno() {
		return sno;
	}
	public void setSno(String sno) {
		this.sno = sno;
	}
	public String getPno() {
		return pno;
	}
	public void setPno(String pno) {
		this.pno = pno;
	}
	public String getKno() {
		return kno;
	}
	public void setKno(String kno) {
		this.kno = kno;
	}
	public int getPrprize() {
		return prprize;
	}
	public void setPrprize(int prprize) {
		this.prprize = prprize;
	}
	public int getPnum() {
		return pnum;
	}
	public void setPnum(int pnum) {
		this.pnum = pnum;
	}
	public Date getPdate() {
		return pdate;
	}
	public void setPdate(Date datetime) {
		this.pdate = datetime;
	}
	
}
