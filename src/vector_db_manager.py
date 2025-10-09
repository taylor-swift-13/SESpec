
import os
import threading
from typing import Optional, Dict, Any
from vector_db import LangChainVectorDB, process_json_to_langchain_db

class VectorDBManager:
    """Vector database singleton manager"""
    
    _instance = None
    _lock = threading.Lock()
    _initialized = False
    
    def __new__(cls):
        if cls._instance is None:
            with cls._lock:
                if cls._instance is None:
                    cls._instance = super().__new__(cls)
        return cls._instance
    
    def __init__(self):
        if not self._initialized:
            with self._lock:
                if not self._initialized:
                    self._vector_db: Optional[LangChainVectorDB] = None
                    self._db_path: Optional[str] = None
                    self._persist_directory: Optional[str] = None
                    self._initialized = True
    
    def get_vector_db(self, db_path: str = None, persist_directory: str = "./VectorDB/chroma_db") -> LangChainVectorDB:
        """
        Get vector database instance
        If database is not initialized, create new instance
        If database is initialized but path is different, reinitialize
        """
        if self._vector_db is None or (db_path and db_path != self._db_path):
            with self._lock:
                if self._vector_db is None or (db_path and db_path != self._db_path):
                    self._initialize_db(db_path, persist_directory)
        
        return self._vector_db
    
    def _initialize_db(self, db_path: str, persist_directory: str):
        """Initialize vector database"""
        print(f"🔧 Initializing vector database...")
        print(f"   Database path: {db_path}")
        print(f"   Persist directory: {persist_directory}")
        
        try:
            if db_path and os.path.exists(db_path):
                # Load database instance from existing ChromaDB file
                self._vector_db = LangChainVectorDB(persist_directory)
                self._db_path = db_path
                self._persist_directory = persist_directory
                print(f"✅ Vector database loaded successfully")
                
            else:
                # Initialize database using specified JSON file
                self._vector_db = process_json_to_langchain_db(db_path, persist_directory, mode='init')
                self._db_path = db_path
                self._persist_directory = persist_directory
                print(f"✅ Vector database initialized successfully")
                
        except Exception as e:
            print(f"❌ Vector database initialization failed: {str(e)}")
            # Create empty database instance as fallback
            self._vector_db = LangChainVectorDB(persist_directory)
            self._db_path = db_path
            self._persist_directory = persist_directory
            print(f"⚠️ Using empty database instance as fallback")
    
    def reload_db(self, db_path: str, persist_directory: str = "./VectorDB/chroma_db"):
        """Reload database"""
        with self._lock:
            self._vector_db = None
            self._db_path = None
            self._persist_directory = None
            self._initialize_db(db_path, persist_directory)
    
    def is_initialized(self) -> bool:
        """Check if database is initialized"""
        return self._vector_db is not None
    
    def get_db_info(self) -> Dict[str, Any]:
        """Get database information"""
        return {
            "initialized": self.is_initialized(),
            "db_path": self._db_path,
            "persist_directory": self._persist_directory,
            "has_data": self._vector_db is not None and hasattr(self._vector_db, 'vectorstore')
        }

# Global singleton instance
_vector_db_manager = None

def get_vector_db_manager() -> VectorDBManager:
    """Get global vector database manager instance"""
    global _vector_db_manager
    if _vector_db_manager is None:
        _vector_db_manager = VectorDBManager()
    return _vector_db_manager

def get_vector_db(db_path: str = None, persist_directory: str = "./VectorDB/chroma_db") -> LangChainVectorDB:
    """Convenience function: get vector database instance"""
    manager = get_vector_db_manager()
    return manager.get_vector_db(db_path, persist_directory) 