import React, { useState } from 'react';
import './Header.css';
import { SearchSharp, VideoCallSharp, AppsSharp, MenuSharp, NotificationsSharp} from '@mui/icons-material';
import { Avatar } from '@mui/material';
import { Link } from 'react-router-dom';

function Header() {
  const [inputSearch, setInputSearch] = useState("")

  return (
    <div className='header'>
      
      <div className='header_left'>
        <MenuSharp/>
        <Link to="/">
          <img className='header_logo'
            src='https://upload.wikimedia.org/wikipedia/commons/b/b8/YouTube_Logo_2017.svg'
            alt=''/>
        </Link>
      </div>

      <div className='header_search'>
        <input 
          onChange={(e) => setInputSearch(e.target.value)} 
          value={inputSearch} 
          placeholder='Search' 
          type='text'
        />
        <Link to={`/search/${inputSearch}`}>
          <SearchSharp className='header_search_icon'/>
        </Link>
      </div>

      <div className='header_right'>
        <VideoCallSharp className='header_icon'/>
        <AppsSharp className='header_icon'/> 
        <NotificationsSharp className='header_icon'/>
        <Avatar
          alt='Willy'
          src='https://th.bing.com/th/id/OIP.NqY3rNMnx2NXYo3KJfg43gHaHa?pid=ImgDet&rs=1'/>
      </div>
      
    </div>
  )
}

export default Header