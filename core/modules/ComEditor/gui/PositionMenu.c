class COM_PositionMenu extends PopupMenu
{
	protected TextListboxWidget m_LstPositionList;
	protected EditBoxWidget m_TxtSelectedX;
	protected EditBoxWidget m_TxtSelectedY;
	protected EditBoxWidget m_TxtCurrentX;
	protected EditBoxWidget m_TxtCurrentY;
	protected ButtonWidget m_TeleportButton;
	protected ButtonWidget m_CancelButton;

	autoptr map< string, vector > Positions = new map< string, vector >;

	protected bool m_bOverCurrentPos;

	void COM_PositionMenu()
	{
		m_bOverCurrentPos = false;

		Positions.Insert( "Kemen Airstrip", "4061 0 8935" );
        Positions.Insert( "Shauninka", "3299 0 8095" );
        Positions.Insert( "Fersen Prison", "2875 0 7363" );
        Positions.Insert( "Noradeshko", "3783 0 7888" );
        Positions.Insert( "Kalemka", "6058 0 7417" );
        Positions.Insert( "Valning Theme Park", "5128 0 6639" );
        Positions.Insert( "Paulaner", "4114 0 6942" );
        Positions.Insert( "Kerl", "4555 0 6450" );
        Positions.Insert( "Jagger Vault", "8067 0 5741" );
        Positions.Insert( "Famka", "7367 0 5675" );
        Positions.Insert( "Guerstling", "5485 0 5187" );
        Positions.Insert( "Otha Island", "3706 0 5756" );
        Positions.Insert( "Blinka", "2435 0 5595" );
        Positions.Insert( "Vezga", "3973 0 4761" );
        Positions.Insert( "Eshkoe Military", "6180 0 4207" );
        Positions.Insert( "Eshkoe", "6124 0 3811" );
        Positions.Insert( "Tervia", "5207 0 3503" );
        Positions.Insert( "Vishky Mountain", "7847 0 4359" );
        Positions.Insert( "Smokinki", "8246 0 4833" );
        Positions.Insert( "Winaud Castle", "4114 0 3642" );
        Positions.Insert( "Gresovia", "3454 0 3657" );
        Positions.Insert( "Kreozky", "2962 0 2943" );
        Positions.Insert( "Loebek", "2794 0 1695" );
        Positions.Insert( "Seroe", "3476 0 1487" );
        Positions.Insert( "Airforce Base", "2946 0 714" );
        Positions.Insert( "Oshkey Radio", "7009 0 1257" );
        Positions.Insert( "Vezerovsky", "7131 0 2659" );
        Positions.Insert( "Hansking", "7839 0 1691" );
        Positions.Insert( "Kaelka", "8355 0 651" );
        Positions.Insert( "Clear Military", "8808 0 1251" );
        Positions.Insert( "Blackwater Castle", "8393 0 1799" );

	}

	void ~COM_PositionMenu()
	{
	}

	void Init()
	{
		m_LstPositionList = TextListboxWidget.Cast( layoutRoot.FindAnyWidget("tls_ppp_pm_positions_list") );
		m_TxtSelectedX = EditBoxWidget.Cast( layoutRoot.FindAnyWidget("pnl_ppp_pm_selected_x_value") );
		m_TxtSelectedY = EditBoxWidget.Cast( layoutRoot.FindAnyWidget("pnl_ppp_pm_selected_y_value") );
		m_TxtCurrentX = EditBoxWidget.Cast( layoutRoot.FindAnyWidget("pnl_ppp_pm_current_x_value") );
		m_TxtCurrentY = EditBoxWidget.Cast( layoutRoot.FindAnyWidget("pnl_ppp_pm_current_y_value") );
		m_TeleportButton = ButtonWidget.Cast( layoutRoot.FindAnyWidget("btn_ppp_pm_teleport") );
		m_CancelButton = ButtonWidget.Cast( layoutRoot.FindAnyWidget("btn_ppp_pm_cancel") );

		for ( int nPosition = 0; nPosition < Positions.Count(); nPosition++ )
		{
			m_LstPositionList.AddItem( Positions.GetKey( nPosition ), NULL, 0 );
		}
	}

	override void OnShow()
	{
		vector player_pos = GetGame().GetPlayer().GetPosition();

		m_TxtCurrentX.SetText( player_pos[0].ToString() );
		m_TxtCurrentY.SetText( player_pos[2].ToString() );
	}

	override void OnHide()
	{

	}

	override bool OnMouseEnter(Widget w, int x, int y)
	{
		if ( w == m_TxtCurrentX || w == m_TxtCurrentY )
		{
			m_bOverCurrentPos = true;
		}

		return false;
	}

	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		if ( w == m_TxtCurrentX || w == m_TxtCurrentY )
		{
			m_bOverCurrentPos = false;
		}

		return false;
	}

	override bool OnKeyPress( Widget w, int x, int y, int key )
	{
		if ( m_bOverCurrentPos )
		{
			m_TxtSelectedX.SetText( "" );
			m_TxtSelectedY.SetText( "" );
		}

		return false;
	}

	override bool OnClick( Widget w, int x, int y, int button )
	{
		if ( w == m_TeleportButton )
		{
			float pos_x = 0;
			float pos_y = 0;

			if( ( m_TxtSelectedX.GetText() != "" ) && ( m_TxtSelectedY.GetText() != "" ) )
			{
				pos_x = m_TxtSelectedX.GetText().ToFloat();
				pos_y = m_TxtSelectedY.GetText().ToFloat();
			}
			else if( ( m_TxtCurrentX.GetText() != "" ) && ( m_TxtCurrentY.GetText() != "" ) )
			{
				pos_x = m_TxtCurrentX.GetText().ToFloat();
				pos_y = m_TxtCurrentY.GetText().ToFloat();
			}
			else
			{
				PlayerBase oPlayer = GetGame().GetPlayer();
				oPlayer.MessageStatus( "Invalid teleportation position!" );

				return true;
			}

			vector vPlayerPos;
			vPlayerPos[0] = pos_x;
			vPlayerPos[2] = pos_y;

			vPlayerPos = SnapToGround( vPlayerPos );

			GetGame().GetPlayer().SetPosition( vPlayerPos );

			return true;
		}

		return false;
	}

	override bool OnItemSelected( Widget w, int x, int y, int row, int column, int oldRow, int oldColumn )
	{
		vector position = "0 0 0";

		if( !Positions.Find( GetCurrentPositionName(), position ) )
		{
			position = "0 0 0";
		}

		m_TxtSelectedX.SetText( position[0].ToString() );
		m_TxtSelectedY.SetText( position[2].ToString() );

		return true;
	}

	string GetCurrentPositionName()
	{
		if ( m_LstPositionList.GetSelectedRow() != -1 )
		{
			string position_name;
			m_LstPositionList.GetItemText( m_LstPositionList.GetSelectedRow(), 0, position_name );
			return position_name;
		}

		return "";
	}
}