import React from 'react';
import './SidebarRow.css';

function SidebarRow( {title, Icon, selected} ) {
  return (
    <div className={`sidebar_row ${selected && "selected"}`}>
        <Icon className='sidebar_row_icon'/>
        <h2 className='sidebar_row_title'> {title} </h2>
    </div>
  )
}

export default SidebarRow