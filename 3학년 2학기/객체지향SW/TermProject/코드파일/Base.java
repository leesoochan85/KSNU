import java.util.Arrays;
import java.util.*;
import java.io.*;

public class Base{
    class Customer{
        protected String Ph, Menu, Address, Name, store;
        protected int Number;

        public String getMenu(){
            return Menu;
        }
        public void setMenu(String Menu){
            this.Menu=Menu;
        }

        public int getNumber(){
            return Number;
        }
        public void setNumber(int Number){
            this.Number=Number;
        }
        
        public void CheckOrder(Owner o){
            int m = o.map.get(this.Menu);
            if(o.MenuCnt[m]<Number ){
                System.out.println("준비된 수량이 "+ o.MenuCnt[m]+ "개 이하입니다.");
            }
        }
    }

    class Order{ 
        protected String Ph, Menu, Address, store;
        protected int Number, OrderNum=0;
        public Order(){
            System.out.println("주문 대기중입니다.");
        }
        public void setCustomer(Customer c){
            this.Ph=c.Ph;
            this.Menu=c.Menu;
            this.Address=c.Address;
            this.store=c.store;
            this.Number=c.Number;
        }
        public int getOrderNum(){
            OrderNum++;
            return OrderNum;
        }
        public void close(){
            System.out.println("주문이 접수되었습니다.");
        }
    }

    class Owner{
        protected String store, Ph, Menu, Address;
        protected int CallDelivery=0;
        protected int []MenuCnt=new int [5];
        Map <String, Integer> map = new HashMap<>();{
            map.put("Salad", 0);
            map.put("Chicken", 1);
            map.put("Pizza", 2);
            map.put("Hamburger", 3);
            map.put("Pasta", 4);
            
            Arrays.fill(MenuCnt,10);
        }

        public void setMenu(Customer c){
            int m = map.get(c.Menu);
            if(MenuCnt[m]>=c.Number ){
                System.out.println("고객 메뉴: "+ c.Menu);
                System.out.println("주문 수량: "+ c.Number);
                MenuCnt[m]-=c.Number;
            }
        }

        public void startCooking(){
            System.out.println("음식 조리가 시작됐습니다.");
        }

        public void getDelivery(Customer c){
            this.store=c.store;
            this.Ph=c.Ph;
            this.Menu=c.Menu;
            this.Address=c.Address;
            CallDelivery++;
        }
        public void close(){
            System.out.println("음식조리가 완료 되었습니다.");
        }
    }


    class Delivery{
        String store, Ph, Menu, Address;

        public void setDelivery(Owner o){
            this.store=o.store;
            this.Ph=o.Ph;
            this.Menu=o.Menu;
            this.Address=o.Address;
        }
        public Delivery(){
            System.out.println("주문하신 음식이 이동중입니다.");
        }
        protected void close(){
            System.out.println("주문하신 음식이 배달완료되었습니다.");
        }
    }

    public static void main(String[]args)throws IOException{
        
    }
}